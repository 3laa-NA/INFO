#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
#include "liste.h"
#include "abr.h"

int main(int argc, char **argv)
{
  /* a completer. Exercice 3, question 1 */

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <mot_a_chercher> <nombre_de_repetitions>\n", argv[0]);
    return 1;
  }


  const char *mot = argv[1]; //mot_a_chercher
  int  iter = atoi(argv[2]); //nombre_de_repetitions

  Lm_mot *l = lire_dico_Lmot("french_za");

  Nd_mot *dico=Lm2abr(l);

  for(int i=0;i<iter;i++){
    chercher_Nd_mot(dico,mot);
  }

  detruire_abr_mot(dico);

  return 0;
}
