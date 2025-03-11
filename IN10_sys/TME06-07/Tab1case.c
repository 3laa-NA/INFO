/* Diffusion tampon 1 case */

  #include <stdio.h> 
  #include <unistd.h> 
  #include <stdlib.h> 
  #include <signal.h> 
  #include <libipc.h>

/************************************************************/

/* definition des parametres */ 

  #define NE          2     /*  Nombre d'emetteurs         */ 
  #define NR          5     /*  Nombre de recepteurs       */ 

/************************************************************/

/* definition des semaphores */ 

int EMET;
int RECEP[NR];
int mutex_nb_recepteurs;

/************************************************************/

/* definition de la memoire partagee */ 

typedef struct {
    int message;
    int nb_recepteurs;
} shared_data;

shared_data *sp;

/************************************************************/

/* variables globales */ 
  int emet_pid[NE], recep_pid[NR]; 

/************************************************************/

/* traitement de Ctrl-C */ 

  void handle_sigint(int sig) { 
    int i;
    for (i = 0; i < NE; i++) kill(emet_pid[i], SIGKILL); 
    for (i = 0; i < NR; i++) kill(recep_pid[i], SIGKILL); 
    det_sem(); 
    det_shm((char *)sp); 
  } 

/************************************************************/

/* fonction EMETTEUR */ 

void emetteur() {
    while (1) {
        P(EMET); // Attendre qu'une case soit libre

        // Écrire le message dans le tampon
        sp->message = rand() % 100; // Exemple de message aléatoire
        printf("Emetteur %d a produit le message %d\n", getpid(), sp->message);

        // Débloquer tous les récepteurs
        for (int i = 0; i < NR; i++) {
            V(RECEP[i]);
        }
    }
}

/************************************************************/

/* fonction RECEPTEUR */ 

void recepteur(int id) {
    while (1) {
        P(RECEP[id]); // Attendre qu'un message soit disponible

        // Lire le message du tampon
        int message = sp->message;
        printf("Recepteur %d a lu le message %d\n", getpid(), message);

        // Protéger l'accès à nb_recepteurs
        P(mutex_nb_recepteurs);
        sp->nb_recepteurs++;
        if (sp->nb_recepteurs == NR) {
            sp->nb_recepteurs = 0;
            V(EMET); // Signaler aux émetteurs qu'une case est libre
        }
        V(mutex_nb_recepteurs);
    }
}

/************************************************************/

int main() { 
  struct sigaction action;
  /* autres variables (a completer) */
  int i;
  
  setbuf(stdout, NULL);

/* Creation du segment de memoire partagee */

  sp = (shared_data *)init_shm(sizeof(shared_data));
  if (sp == NULL) {
      perror("init_shm");
      exit(EXIT_FAILURE);
  }

/* creation des semaphores */ 

  if (creer_sem(2 + NR) == -1) {
      perror("creer_sem");
      exit(EXIT_FAILURE);
  }
  EMET = 0;
  mutex_nb_recepteurs = 1;
  for (i = 0; i < NR; i++) {
      RECEP[i] = 2 + i;
  }

/* initialisation des semaphores */ 

  if (init_un_sem(EMET, 1) == -1 || init_un_sem(mutex_nb_recepteurs, 1) == -1) {
      perror("init_un_sem");
      exit(EXIT_FAILURE);
  }
  for (i = 0; i < NR; i++) {
      if (init_un_sem(RECEP[i], 0) == -1) {
          perror("init_un_sem");
          exit(EXIT_FAILURE);
      }
  }

/* creation des processus emetteurs */ 

  for (i = 0; i < NE; i++) {
      if ((emet_pid[i] = fork()) == 0) {
          emetteur();
          exit(EXIT_SUCCESS);
      }
  }

/* creation des processus recepteurs */ 

  for (i = 0; i < NR; i++) {
      if ((recep_pid[i] = fork()) == 0) {
          recepteur(i);
          exit(EXIT_SUCCESS);
      }
  }

/* redefinition du traitement de Ctrl-C pour arreter le programme */

  sigemptyset(&action.sa_mask);
  action.sa_flags = 0;
  action.sa_handler = handle_sigint;
  sigaction(SIGINT, &action, 0); 
  
  pause();                    /* attente du Ctrl-C  */
  return EXIT_SUCCESS;
}
