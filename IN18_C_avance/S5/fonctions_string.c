#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "devel.h"

void *dupliquer_str(const void *src) {
  const char *strsrc = (const char *)src;
  char *strdst = malloc(strlen(strsrc) + 1);

  if (strdst == NULL) {
    affiche_message("Erreur d'allocation");
    return NULL;
  }

  strcpy(strdst, strsrc);
  return (void *)strdst;
}

void copier_str(const void *src, void *dst) {
  const char *strsrc = (const char *)src;
  char *strdst = (char *)dst;
  strcpy(strdst, strsrc);
}

void detruire_str(void *data) {
  free(data);
}

void afficher_str(const void *data) {
  const char *strdata = (const char *)data;
  printf("%s", strdata);
}

int comparer_str(const void *a, const void *b) {
  const char *stra = (const char *)a;
  const char *strb = (const char *)b;
  return strcmp(stra, strb);
}

int ecrire_str(const void *data, FILE *f) {
  const char *strdata = (const char *)data;
  return fprintf(f, "%s", strdata);
}

void *lire_str(FILE *f) {
  char ch[1024];
  int r = fscanf(f, " %1023s", ch);

  if (r < 1) {
    return NULL;
  }

  char *pch = malloc(strlen(ch) + 1);
  strcpy(pch, ch);
  return pch;
}
