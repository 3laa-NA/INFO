#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioLC.h"

Livre* creer_livre(int num,char* titre,char* auteur){
    Livre* new = (Livre*)malloc(sizeof(Livre));

    new->num = num;
    new->titre = titre;
    new->auteur = auteur;
    new->suiv = NULL;

    return new;
}


void liberer_livre(Livre* l){
    free (l);
}

Biblio* creer_biblio(){
    Biblio* b = (Biblio*)malloc(sizeof(Biblio));
    b->L = NULL;

    return b;
}


void liberer_biblio(Biblio* b){
    while(b->L != NULL){
        Livre* tmp = b->L;
        b->L = b->L->suiv;
        liberer_livre(tmp);
    }

    free(b);
}

void inserer_en_tete(Biblio* b,int num,char* titre,char* auteur){
    Livre* l = creer_livre(num,titre,auteur);
    l->suiv = b->L;
    b->L = l; 
}



int main(int argc, char const *argv[]){

    char * titre = "ch";
    Livre* l = creer_livre(05,titre,"mo");
    titre = "hello";
    printf("%d %s %s  %s\n", l->num,l->titre , l-> auteur,titre);
    return 0;
}
