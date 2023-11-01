#include <assert.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <strings.h>
#include "ecosys.h"
#include "ecosys.c"



#define NB_PROIES 40
#define NB_PREDATEURS 40
#define T_WAIT 100000
#define FICHIER "Evol_Pop.txt" //nom du fichier pour stocker les donnees
#define ITER 500 //n° d'iterations



int main(void) {

  float energie = 30;
 
  Animal * new = creer_animal(0,10, energie);

  Animal * proie = new;

  for (int i=0 ; i < NB_PROIES; i++){
    Animal *new = creer_animal(rand()%SIZE_X,rand()%SIZE_Y, energie);
    proie = ajouter_en_tete_animal(proie,new);
  }

  Animal * pred=NULL;

  for (int i=0 ; i < NB_PROIES; i++){
    Animal *new = creer_animal(rand()%SIZE_X,rand()%SIZE_Y, energie);
    pred = ajouter_en_tete_animal(pred,new);
  }
  
  //on cree monde (0 partout)
  int monde[SIZE_X][SIZE_Y] = {0};

  int i = 0;

  FILE *file = fopen(FICHIER, "w");

  while (i < ITER && (proie || pred)){
    clear_screen();
    rafraichir_monde(monde);
    rafraichir_proies(&proie, monde);
    rafraichir_predateurs(&pred,&proie);
    afficher_ecosys(proie, pred);
    usleep(T_WAIT);
    fprintf(file, "%d %d %d\n",i ,compte_animal_rec(proie),compte_animal_rec(pred));
    i++;
  }

  return 0;
}

