#include <stdlib.h>
#include <stdio.h>
#include "arbre_lexicographique_tab.h"

int main(int argc, char **argv) {

  /* a completer. Exercice 6, question 2 */

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <mot_a_chercher> <nombre_de_repetitions>\n", argv[0]);
    return 1;
  }


  char *mot = argv[1]; //mot_a_chercher
  int  iter = atoi(argv[2]); //nombre_de_repetitions

  PNoeudTab dico = lire_dico("french_za");

  //afficher_dico(dico);

  for(int i=0;i<iter;i++){
    rechercher_mot(dico,mot);
  }

  detruire_dico(dico);

  return 0;
}
