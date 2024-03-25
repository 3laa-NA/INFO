#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Hachage.h"

int fonctionClef(double x, double y){
    return (x+y)*(x+y+1)/2.0+y;
}

int fonctionHachage(int k, int m){
    float a = (sqrt(5)-1)/2 ;
    return (int)(m*(k*a - (int)(k*a)));
}

Noeud* rechercheCreeNoeudHachage(Reseau* R, TableHachage* H, double x, double y){
    Noeud *res;

    rechercheCreeNoeudListe(R, x, y);

    return res;
}

int main(){



    return 0;
}