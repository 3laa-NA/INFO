#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "devel.h"
#include "liste.h"
#include "fonctions_2entiers.h"
#include "fonctions_string.h"

/*

void compte(void *data, void *optarg) {
  // a completer. Exercice 6, question 2 
  char *mot = (char *)data;
  Liste *resultats = (Liste *)optarg;

  // Calculer la longueur du mot
  int longueur = strlen(mot);

  // Rechercher si la longueur est déjà dans la liste des résultats
  Double_int *element = chercher(resultats, &longueur, comparer_2int);

  if (element != NULL) {
    // Si la longueur est déjà dans la liste, incrémenter le nombre de mots
    element->b++;
  } else {
    // Si la longueur n'est pas dans la liste, ajouter un nouvel élément
    Double_int nouvel_element = {longueur, 1};
    inserer(resultats, dupliquer_2int(&nouvel_element), comparer_2int);
  }
}



int main(void) {
  // a completer. Exercice 6, question 2 
  FILE *fichier = fopen("french", "r");
  assert(fichier != NULL);

  Liste *resultats = initialiser_liste();

  // Charger le dictionnaire et compter les mots
  map(fichier, compte, resultats);

  // Afficher les résultats
  afficher_liste(resultats);

  // Libérer la mémoire
  vider_liste(resultats, detruire_2int);
  fclose(fichier);

  return 0;
}

*/