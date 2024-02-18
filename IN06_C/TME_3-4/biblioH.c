#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "biblioH.h"

int fonctionClef(char* auteur){
    int res=0;
    for(int i=0; i<strlen(auteur); i++){
        res+=auteur[i];
    }

    return res;
}

LivreH* creer_livre(int num,char* titre,char* auteur){
    LivreH* new = (LivreH*)malloc(sizeof(LivreH));

    new->num = num;
    new->titre = strdup(titre);
    new->auteur = strdup(auteur);
    new->suivant = NULL;

    return new;
}

void liberer_livre(LivreH* l){
    free(l->titre);
    free(l->auteur);

    free (l);
}



BiblioH* creer_biblio(int m){
    BiblioH* b = (BiblioH*)malloc(sizeof(BiblioH));
    b->nE = 0;
    b->m = m;
    b->T = (LivreH **)malloc(sizeof(LivreH*)*m);

    return b;
}



void liberer_biblio(BiblioH* b){

    for(int i=0; i<b->m; i++){
        LivreH* tmp = b->T[i];
        while(tmp){
            LivreH *s = tmp;
            tmp=tmp->suivant;
            liberer_livre(s);
        }
    }

    free(b->T);
    free(b);
}

int fonctionHachage(int cle, int m){
    float a = (sqrt(5)-1)/2 ;
    return (int)(m*(cle*a - (int)(cle*a)));
}

void inserer(BiblioH* b,int num,char* titre,char* auteur){
    int i = fonctionHachage(fonctionClef(auteur),b->m);

    LivreH *l = creer_livre(num,titre,auteur);
    l->suivant = b->T[i];

    b->T[i] = l;
}

int main(){

    printf("%d\n", fonctionClef("al"));
    return 0;
}