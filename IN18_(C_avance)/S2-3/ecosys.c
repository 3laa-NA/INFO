#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ecosys.h"

/* Parametres globaux de l’ecosysteme (externes dans le ecosys.h)*/
float p_ch_dir=0.1; //probabilite de changer de direction de deplacement
float p_reproduce_proie=0.4;
float p_reproduce_predateur=0.5;
int temps_repousse_herbe=-15;


/* PARTIE 1*/

/* Fourni */
Animal *creer_animal(int x, int y, float energie) {
  
  //allocation d'une zone memoire
  Animal *na = (Animal *)malloc(sizeof(Animal));
  assert(na);
  na->x = x;
  na->y = y;
  na->energie = energie;
  na->dir[0] = rand() % 3 - 1;
  na->dir[1] = rand() % 3 - 1;
  na->suivant = NULL;
  return na;
}


/* Fourni */
Animal *ajouter_en_tete_animal(Animal *liste, Animal *animal) {
  assert(animal);
  assert(!animal->suivant);
  animal->suivant = liste;
  return animal;
}

/* A faire */
void ajouter_animal(int x, int y,  float energie, Animal **liste_animal) {
  assert (0 <= x && x < SIZE_X && 0 <= y && y < SIZE_Y );
  Animal * new = creer_animal(x,y,energie);
  *liste_animal = ajouter_en_tete_animal(*liste_animal,new);
}

/* A Faire */
void enlever_animal(Animal **liste, Animal *animal) {

  //oon recupere la liste chainee
  Animal *li_ch = *liste;

  //on traite le cas ou l'un des arguments est non existant
  if ( li_ch == NULL || animal == NULL) return;

  //on traite le cas ou l'animal à enlever est en tete de liste
  if(li_ch==animal){
    Animal *tmp=li_ch;
    li_ch=li_ch->suivant;
    free(tmp);
    //puisque la tete est supprimé on met 'liste' à jour 
    *liste = li_ch;
    return;
  }

  else{

    //on garde l'addresse de l'animal precedent dans al liste
    Animal *pre = li_ch;
    li_ch = li_ch->suivant;


    while(li_ch){
      if(li_ch==animal){
        //quand on trouve l'animal on relit l'animal precedent au suivant
        pre->suivant = li_ch->suivant;

        //puis on libere la memoire
        free(li_ch);
        return;
      }
      li_ch=li_ch->suivant;
      pre=pre->suivant;
    }
  }

  //si on est arrive la l'animal n'est pas dans la liste
  printf("l'animal n'est pas dans la liste\n");

  return;
}

/* A Faire */
Animal* liberer_liste_animaux(Animal *liste) {

   while(liste){
    Animal *tmp=liste;
    liste=liste->suivant;
    free(tmp);
   }

  return NULL;
}

/* Fourni */
unsigned int compte_animal_rec(Animal *la) {
  if (!la) return 0;
  return 1 + compte_animal_rec(la->suivant);
}

/* Fourni */
unsigned int compte_animal_it(Animal *la) {
  int cpt=0;
  while (la) {
    ++cpt;
    la=la->suivant;
  }
  return cpt;
}



/* Part 1. Exercice 5, question 1, ATTENTION, ce code est susceptible de contenir des erreurs... */
void afficher_ecosys(Animal *liste_proie, Animal *liste_predateur) {
  unsigned int i, j;
  char ecosys[SIZE_X][SIZE_Y];
  Animal *pa=NULL;

  /* on initialise le tableau */
  for (i = 0; i < SIZE_X; ++i) {
    for (j = 0; j < SIZE_Y; ++j) {
      ecosys[i][j]=' ';
    }
  }

  /* on ajoute les proies */
  pa = liste_proie;
  while (pa) {
    ecosys[pa->x][pa->y] = '*';
    pa=pa->suivant;
  }

  /* on ajoute les predateurs */
  pa = liste_predateur;

  
  while (pa) {
    assert(pa->x < SIZE_X && pa->y <SIZE_Y );
    if ((ecosys[pa->x][pa->y] == '@') || (ecosys[pa->x][pa->y] == '*')) { /* proies aussi present */
      ecosys[pa->x][pa->y] = '@';
    } else {
      ecosys[pa->x][pa->y] = 'O';
    }
    pa = pa->suivant;
  }

  /* on affiche le tableau */
  printf("+");
  for (j = 0; j < SIZE_Y; ++j) {
    printf("-");
  }  
  printf("+\n");
  for (i = 0; i < SIZE_X; ++i) {
    printf("|");
    for (j = 0; j < SIZE_Y; ++j) {
      putchar(ecosys[i][j]);
    }
    printf("|\n");
  }
  printf("+");
  for (j = 0; j<SIZE_Y; ++j) {
    printf("-");
  }
  printf("+\n");
  int nbproie=compte_animal_it(liste_proie);
  int nbpred=compte_animal_it(liste_predateur);
  
  printf("Nb proies : %5d\tNb predateurs : %5d\n", nbproie, nbpred);

}


void clear_screen() {
  printf("\x1b[2J\x1b[1;1H");  /* code ANSI X3.4 pour effacer l'ecran */
}

/* PARTIE 2*/

/* A Faire */
void ecrire_ecosys(const char *nom_fichier, Animal *liste_predateur, Animal *liste_proie){

  //on ouvre le fichier en mode ecriture
  FILE *file = fopen(nom_fichier, "w");

  //on y ecrit
  fprintf(file, "<proies>\n");
  Animal * l1 = liste_proie;
  while(l1){
    fprintf(file, "x=%d y=%d dir=[%d %d] e=%f\n",l1->x,l1->y,l1->dir[0],l1->dir[1],l1->energie);
    l1=l1->suivant;
  }
  fprintf(file, "</proies>\n<predateurs>\n");
  Animal * l2 = liste_predateur;
  while(l2){
    fprintf(file, "x=%d y=%d dir=[%d %d] e=%f\n",l2->x,l2->y,l2->dir[0],l2->dir[1],l2->energie);
    l2=l2->suivant;
  }
  fprintf(file, "</predateurs>\n");

  fclose(file);
}


/* A Faire */
void lire_ecosys(const char *nom_fichier, Animal **liste_predateur, Animal **liste_proie){

  //on ouvre le fichier en mode lecture
  FILE *file = fopen(nom_fichier, "r");

  //en cas d'erreur
  if (file == NULL) {
    printf("erreur fichier non ouvrable (ou non existant).\n");
    return;
  }

  //une variable pour indiquer si le fichier est vide
  int vide = 1;

  char line[200]; 

  while (fgets(line, sizeof(line), file) != NULL) {

    //on est entré dans la boucle donc le fichier n'est pas vide
    vide = 0;
    if (strcmp(line, "<proies>\n") == 0){
      while (fgets(line, sizeof(line), file) != NULL && strcmp(line, "</proies>\n") != 0){
        int x,y,dx,dy;
        float energie;
        sscanf(line, "x=%d y=%d dir=[%d %d] e=%f\n", &x, &y, &dx, &dy, &energie);
        ajouter_animal(x,y,energie,liste_proie);
        (*liste_proie)->dir[0]=dx;
        (*liste_proie)->dir[1]=dy;
      }
    }
    if (strcmp(line, "<predateurs>\n") == 0){
      while (fgets(line, sizeof(line), file) != NULL && strcmp(line, "</predateurs>\n") != 0){
        int x,y,dx,dy;
        float energie;
        sscanf(line, "x=%d y=%d dir=[%d %d] e=%f\n", &x, &y, &dx, &dy, &energie);
        ajouter_animal(x,y,energie,liste_predateur);
        (*liste_predateur)->dir[0]=dx;
        (*liste_predateur)->dir[1]=dy;
      }
    }
  }

  //si le fichier est vide
  if(vide){
    printf("le fichier %s est vide\n",nom_fichier);
  }

  fclose(file);
}


/* A Faire */
void bouger_animaux(Animal *la) {

  while(la){
    
    //on test pour voir si il y a changement de direction
    if(rand()*1./RAND_MAX < p_ch_dir){
      int a = la->dir[0];
      int b = la->dir[1];

      //on prend on compte le cas ou on tompe sur les memes valeurs
      while(a == la->dir[0] && b == la->dir[1]){
        la->dir[0] = rand() % 3 - 1;
        la->dir[1] = rand() % 3 - 1;
      }
    }

    la->x += la->dir[0];

    // on traite les cas ou on sort du monde
    if(la->x >= SIZE_X){
      la->x -= SIZE_X;
    }
    else if(la->x < 0){
      la->x += SIZE_X;
    }

    la->y += la->dir[1];

    if(la->y >= SIZE_Y){
      la->y -= SIZE_Y;
    }
    else if(la->y < 0){
      la->y += SIZE_Y;
    }

    assert(la->x >= 0 && la->y >= 0 && la->x <= SIZE_X && la->y <= SIZE_Y);

    la = la->suivant;
  }

}


/* A Faire */
void reproduce(Animal **liste_animal, float p_reproduce) {

  if(liste_animal){
    //on recupere la tete de la liste
    Animal *ani = *liste_animal;
    while(ani != NULL){

      if(rand()*1./RAND_MAX < p_reproduce){

        //on crée l'animal
        Animal *enfant = creer_animal(ani->x, ani->y, ani->energie/2);
        //on diminue l'energie de parent
        ani->energie /= 2;
        //on ajoute l'animal en tete de liste
        *liste_animal = ajouter_en_tete_animal(*liste_animal, enfant);
      }

      ani = ani->suivant;
    }    
  }

}


/* A Faire */
void rafraichir_proies(Animal **liste_proie, int monde[SIZE_X][SIZE_Y]) {

  //au cas ou liste predateur est vide (ou non existante)
  if(liste_proie == NULL) return;

  Animal *la = *liste_proie;

  // on fait bouger les proies
  bouger_animaux(la);

  while(la){

    la->energie -= 1.;

    if (monde[la->x][la->y]>=0){
      la->energie += monde[la->x][la->y];
      monde[la->x][la->y] = temps_repousse_herbe; 
    }

    if(la->energie <= 0){
      Animal *tmp = la;
      la = la->suivant;
      //on supprime les proies morts
      enlever_animal(liste_proie, tmp);

      //on quitte cette iteration et on va au suivante
      continue;
    }
    
    //si on est arrivee la ca veut dire que la proie a survecu
    la = la->suivant;

  }

  //on appelle reproduce
  reproduce(liste_proie, p_reproduce_proie);

}

/* A Faire */
Animal *animal_en_XY(Animal *l, int x, int y) {

  Animal *la = l;

  while (la){
    //on verifie les coordonnees
    if(la->x == x && la->y == y){
      return la;
    }
    la = la->suivant;
  }

  return NULL;
} 

/* A Faire */
void rafraichir_predateurs(Animal **liste_predateur, Animal **liste_proie) {

  //au cas ou liste predateur est vide (ou non existante)
  if(liste_predateur == NULL) return;

  Animal *la = *liste_predateur;

  // on fait bouger les predateurs
  bouger_animaux(la);

  while(la){
    
    la->energie -= 1.;
    
    //la variable pro qui indique la presence/absence d'une proie
    Animal *pro = NULL;
    if(liste_proie != NULL){ 
      pro = animal_en_XY(*liste_proie, la->x, la->y);
    }

    if(pro){
      //on simule la predation
      la->energie += pro->energie;
      enlever_animal(liste_proie,pro);
    }

    if(la->energie <= 0){
      Animal *tmp = la;
      la = la->suivant;
      //on supprime les predateurs morts
      enlever_animal(liste_predateur, tmp);

      //on quitte cette iteration et on va au suivante
      continue;
    }
    
    //si on est arrivee la ca veut dire que le predateur a survecu
    la = la->suivant;

  }

  //on appelle reproduce
  reproduce(liste_predateur, p_reproduce_predateur);


}

/* A Faire */
void rafraichir_monde(int monde[SIZE_X][SIZE_Y]){

  for(int i = 0; i < SIZE_X; i++){
    for(int j = 0; j < SIZE_Y; j++){
      monde[i][j] += 1;
    }
  }

}

