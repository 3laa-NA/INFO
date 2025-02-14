#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>

#include "tab.h"

#define NMAX 1000000

void printMem(){
    struct rusage usage;

    if (getrusage(RUSAGE_SELF, &usage) == 0) {
        printf("Memoire-residente occupé : %d KB\n", usage.ru_maxrss);
    }
}

int main(void) {

    //int tab[NMAX]; //sur la pile
    int *tab = (int*) malloc(sizeof(int)*NMAX);
    
    printMem();
    InitTab(tab, NMAX); // c'est ici que la mémoire est effectivement allouée
    printMem();


    //PrintTab(tab, NMAX);

    int min;

    printf("Resultat de SumTab    : %d\n", SumTab(tab, NMAX));
    printf("Resultat de MinSumTab : %d\n", MinSumTab(&min, tab, NMAX));
    printf("Valeur mise dans Min  : %d\n", min);

    
    free(tab);

    return 0;
}

