
#include <stdlib.h>
#include "liste.h"
#include "devel.h"
#include "fonctions_entiers.h"
#include <assert.h>

int main(void) {

  /* a completer. Exercice 4, question 1 */

  // Test de dupliquer_int
  int original = 42;
  void *copie = dupliquer_int(&original);

  // Assertion pour vérifier la duplication + test de fonction afficher
  assert(copie != NULL);
  assert(*(int*)copie == original);
  printf("Duplication réussie!\n");
  afficher_int(copie);
  printf("\n");

  // Test de copier_int
  int destination;
  copier_int(copie, &destination);

  assert(destination == original);
  printf("Copie réussie!\n");


  // Test de comparer_int
  int autre_nombre = 21;
  int resultat_comparaison = comparer_int(&original, &autre_nombre);

  assert(resultat_comparaison > 0);
  printf("comparaison réussie!\n");

  // Test de ecrire_int
  FILE *fichier = fopen("test_int.txt", "w");
  assert(fichier != NULL);

  ecrire_int(&original, fichier);
  fclose(fichier);
  printf("Écriture réussie dans le fichier (vaut mieux vérifier en regardant le fichier)!\n");

  // Test de lire_int
  fichier = fopen("test_int.txt", "r");
  assert(fichier != NULL);

  void *lecture = lire_int(fichier);
  fclose(fichier);

  assert(lecture != NULL);
  printf("Lecture réussie depuis le fichier !\nentier lu : ");
  afficher_int(lecture);
  printf("\n");

  // libérer la mémoire
  detruire_int(copie);
  detruire_int(lecture);

  return 0;
}
