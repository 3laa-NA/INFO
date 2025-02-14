#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "tab.h"

void InitTab(int *tab, int size){
    srand(time(NULL));

    for(int i=0; i<size; i++){
        tab[i] = rand()%10;
    }
}

void PrintTab(int *tab, int size){
    if(size == 0){
        printf("Tableau vide!\n");
        return;
    }

    printf("voilà le tableau : [");

    for(int i=0; i<size-1; i++){
        printf("%d, ", tab[i]);
    }

    printf("%d]\n",tab[size-1]);
}

int SumTab(int *tab, int size){
    int res = 0;
    for (int i=0; i<size; i++){
        res += tab[i];
    }
    
    return res;
}

int MinSumTab(int *min, int *tab, int size){
    if(size == 0){
        return 0;
    }

    int res = tab[0];
    *min = res;

    for (int i=1; i<size; i++){

        if (*min > tab[i]){
            *min = tab[i];
        }
        res+=tab[i];
    }

    return res;
}