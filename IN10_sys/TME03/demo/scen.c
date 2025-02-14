#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>
#include <sched.h>

#define LONGTIME 8E8
void ProcLong(int *);
void ProcCourt(int *);

// Exemple de processus long (une simple bouble),
// Chaque processus long cr�e a son tour 4 processus courts
//
void ProcLong(int *pid) {
  long i;
  static int cpt = 0;

  for (i=0;i<LONGTIME;i++) {
    if (i%(long)(LONGTIME/4) == 0)  {
      int *tcpt = (int *) malloc(sizeof(int));
      *tcpt = cpt;
      CreateProc((function_t)ProcCourt,(void *)tcpt, 10);
      cpt++;
    }
    if (i%(long)(LONGTIME/100) == 0)
      printf("Proc. Long %d - %ld\n",*pid, i);
  }
  printf("############ FIN LONG %d\n\n", *pid );
}


// Processus court
void ProcCourt(int *pid) {
  long i;

  for (i=0;i<LONGTIME/10;i++)
    if (i%(long)(LONGTIME/100) == 0)
      printf("Proc. Court %d - %ld\n",*pid, i);
  printf("############ FIN COURT %d\n\n", *pid );
}




// Exemples de primitive d'election definie par l'utilisateur
// Remarques : les primitives d'election sont appel�es directement
//             depuis la librairie. Elles ne sont app�l�es que si au
//             moins un processus est � l'etat pret (RUN)
//             Ces primitives manipulent la table globale des processus
//             d�finie dans sched.h


// Election al�atoire
int RandomElect(void) {
  int i;

  printf("RANDOM Election !\n");

  do {
    i = (int) ((float)MAXPROC*rand()/(RAND_MAX+1.0));
  } while (Tproc[i].flag != RUN);

  return i;
}


// Election de SJF "Shortest Job Fisrt"
int SJFElect(void) {
  int p;
  int min_duration = __INT_MAX__;  // Valeur max pour comparer

  printf("Election SJF!\n");

  for (int i = 0; i < MAXPROC; i++) {
    if (Tproc[i].flag == RUN && Tproc[i].duration < min_duration) {
      min_duration = Tproc[i].duration;
      p = i;
    }
  }

  return p;	
}

// Approximation SJF
int ApproxSJF(void) {
  int p = -1;
  int max_prio = MINPRIO - 1; // Plus grand que la priorité maximale

  printf("ApproxSJF Election (avec priorité) !\n");

  for (int i = 0; i < MAXPROC; i++) {
    if (Tproc[i].flag == RUN && Tproc[i].prio > max_prio) {
      max_prio = Tproc[i].prio;
      p = i;
    }
  }

  int miskin; //proc qui a utilisé le moins de "cpu"
  int min_ncpu = __INT_MAX__;

  for (int i = 0; i < MAXPROC; i++) {
    if (Tproc[i].flag == RUN && Tproc[i].ncpu < min_ncpu) {
      min_ncpu = Tproc[i].prio;
      miskin = i;
    }
  }  
  
  Tproc[miskin].prio = (Tproc[miskin].prio < MAXPRIO) ? Tproc[miskin].prio + 1 : MAXPRIO;
  Tproc[p].prio = (Tproc[p].prio > MINPRIO) ? Tproc[p].prio - 1 : MINPRIO;

  return p;
}



int main (int argc, char *argv[]) {
  int i;
  int *j;  

  // Cr�er les processus long
  for  (i = 0; i < 2; i++) {
    j = (int *) malloc(sizeof(int));
    *j= i;
    CreateProc((function_t)ProcLong,(void *)j, 80);
  }



  // Definir une nouvelle primitive d'election avec un quantum de 1 seconde
  //SchedParam(NEW, 1, RandomElect);
  //SchedParam(NEW, 1, SJFElect);
  SchedParam(NEW, 1, ApproxSJF);

  // Lancer l'ordonnanceur en mode non "verbeux"
  sched(0);     

  // Imprimer les statistiques
  PrintStat();

  return EXIT_SUCCESS;

}
