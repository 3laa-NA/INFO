#include <stdlib.h>
#include "liste.h"
#include "devel.h"
#include "fonctions_string.h"
#include <string.h>
#include <assert.h>

int main(void) {

  // Test de dupliquer_str
  const char *original = "ok";
  void *copie = dupliquer_str(original);

  // Assertion pour vérifier la duplication + test de fonction afficher_str
  assert(copie != NULL);
  assert(strcmp(original, (char*)copie) == 0);
  printf("Duplication réussie!\n");
  afficher_str(copie);
  printf("\n");

  // Test de copier_str
  char destination[3];
  copier_str(copie, destination);

  assert(strcmp(destination, original) == 0);
  printf("Copie réussie!\n");

  // Test de comparer_str
  const char *autre_str = "ko";
  int resultat_comparaison = comparer_str(original, autre_str);

  assert(resultat_comparaison > 0);
  printf("Comparaison réussie!\n");

  // Test de ecrire_str
  FILE *fichier = fopen("test_str.txt", "w");
  assert(fichier != NULL);

  ecrire_str(original, fichier);
  fclose(fichier);
  printf("Écriture réussie dans le fichier (vaut mieux vérifier en regardant le fichier)!\n");

  // Test de lire_str
  fichier = fopen("test_str.txt", "r");
  assert(fichier != NULL);

  void *lecture = lire_str(fichier);
  fclose(fichier);

  assert(lecture != NULL);
  printf("Lecture réussie depuis le fichier !\nChaine lue : ");
  afficher_str(lecture);
  printf("\n");

  // Libérer la mémoire
  detruire_str(copie);
  detruire_str(lecture);

  return 0;

}
