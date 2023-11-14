#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "ecosys.h"



int main(void) {
  Animal *liste_proie = NULL;
  Animal *liste_predateur = NULL;
  float energie=10;

  srand(time(NULL));

  Animal *a1 = creer_animal(0,10, energie);
  Animal *a2 = creer_animal(15,35, energie);
  Animal *a3 = creer_animal(2,42, energie);
  Animal *a4 = creer_animal(18,13, energie);
  
  a1->suivant=a2;
  a2->suivant=a3;
  a3->suivant=a4;

  liste_proie=a1;

  Animal *a5 = creer_animal(2,5, energie);
  Animal *a6 = creer_animal(15,35, energie);
  Animal *a7 = creer_animal(9,22, energie);
  Animal *a8 = creer_animal(17,3, energie);
  
  a5->suivant=a6;
  a6->suivant=a7;
  a7->suivant=a8;

  liste_predateur=a5;
  
  //test de fonction affiche
  afficher_ecosys(liste_proie,liste_predateur);
  
  //on ajoute un predateur en plus
  ajouter_animal(2,6,energie,&liste_predateur); 

  //on ecrit
  ecrire_ecosys("ecosys.txt",liste_predateur,liste_proie); 

  Animal *liste_proie2 = NULL;
  Animal *liste_predateur2 = NULL;

  //puis on relit et on stock dans des nouvelles listes
  lire_ecosys("ecosys.txt",&liste_predateur2,&liste_proie2);
  //on affiche pour voir si les listes etaient bien ecrites et lues (avec l'animal en plus)
  afficher_ecosys(liste_proie2,liste_predateur2);

  //on test reproduce
  reproduce(&liste_predateur2,p_reproduce_predateur);
  reproduce(&liste_proie2,p_reproduce_proie);

  //on test bouger
  bouger_animaux(liste_predateur2);
  bouger_animaux(liste_proie2);
  
  //on affiche pour voir l'effet
  afficher_ecosys(liste_proie2,liste_predateur2);

  //on libere la memoire
  liberer_liste_animaux(liste_proie);
  liberer_liste_animaux(liste_proie2);
  liberer_liste_animaux(liste_predateur);
  liberer_liste_animaux(liste_predateur2);

  Animal * new2 = creer_animal(0,10, energie);

  //on test la fonction animal en XY
  assert(animal_en_XY(new2,0,10));

  //on test la fonction enlever
  enlever_animal(&new2,new2);
  assert (!new2);

  return 0;
}
