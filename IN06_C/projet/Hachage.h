#ifndef __HACHAGE_H__
#define __HACHAGE_H__
#include "Reseau.h"

typedef struct{
  int nbElement; //pas necessaire ici
  int tailleMax;
  CellNoeud** T;
} TableHachage ;


int fonctionClef(double x, double y);

int fonctionHachage(int k, int m);

Noeud* rechercheCreeNoeudHachage(Reseau* R, TableHachage* H, double x, double y);

#endif