#include <stdlib.h>
#include <stdio.h>
#include "devel.h"

#include "fonctions_2entiers.h"

void *dupliquer_2int(const void *src) {
  /* a completer. Exercice 6, question 1 */
  Double_int *isrc=(Double_int *)src;
  Double_int *idst=malloc(sizeof(Double_int));
  if (idst==NULL) {
    affiche_message("Erreur d'allocation");
    return NULL;
  }
  idst->a = isrc->a;
  idst->b = isrc->b;
  return (void *)idst;
}

void copier_2int(const void *src, void *dst) {
  /* a completer. Exercice 6, question 1 */
  Double_int *isrc=(Double_int *)src;
  Double_int *idst=(Double_int *)dst;
  idst->a=isrc->a;
  idst->b=isrc->b;
}

void detruire_2int(void *data) {
  /* a completer. Exercice 6, question 1 */
  free(data);
}

void afficher_2int(const void *data) {
  /* a completer. Exercice 6, question 1 */
  Double_int *idata=(Double_int *)data;
  printf("a=%d b=%d",idata->a,idata->b);
}

int comparer_2int(const void *a, const void *b) {
  /* a completer. Exercice 6, question 1 */
  Double_int *i1 = (Double_int *)a;
  Double_int *i2 = (Double_int *)b;
  return (i1->a>i2->a)-(i1->a<i2->a);
}

int ecrire_2int(const void *data, FILE *f) {
  /* a completer. Exercice 6, question 1 */
  const Double_int *idata=(const Double_int *)data;
  return fprintf(f,"a=%d b=%d",idata->a,idata->b);
}

void * lire_2int(FILE *f) {
  /* a completer. Exercice 6, question 1 */
  Double_int *i= malloc(sizeof(Double_int));
  int r=fscanf(f," a=%d b=%d", &(i->a), &(i->b));
  if (r<1) return NULL;

  return (void *)i;
}
