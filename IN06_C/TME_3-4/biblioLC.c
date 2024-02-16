#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioLC.h"

Livre* creer_livre(int num,char* titre,char* auteur){
    Livre* new = (Livre*)malloc(sizeof(Livre));

    new->num = num;
    new->titre = strdup(titre);
    new->auteur = strdup(auteur);
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


void afficher_livre(Livre *l){
    printf("Livre numéro: %d\n   Titre: %s\n   Auteur: %s\n",l->num,l->titre,l->auteur);
}

void afficher_biblio(Biblio *b){
    Livre *tmp = b->L;
    if(tmp){
        printf("La biblio contient le(s) livre(s):\n");
    }else{
        printf("Le biblio est vide\n");
    }
    while(tmp){
        afficher_livre(tmp);
        tmp = tmp->suiv;
    }
}

Livre *recherche_livre_num(Biblio *b,int n){
    Livre *tmp = b->L;
    if(!tmp){
        printf("Le biblio est vide!\n");
        return NULL;
    }
    while(tmp){
        if(tmp->num == n){
            return tmp;
        }
        tmp=tmp->suiv;
    }
    
    printf("Livre non trouvé par numéro!\n");
    return NULL;
}


Livre *recherche_livre_titre(Biblio *b,char *tit){
    Livre *tmp = b->L;
    if(!tmp){
        printf("Le biblio est vide!\n");
        return NULL;
    }
    while(tmp){
        if(strcmp(tmp->titre,tit) == 0){
            return tmp;
        }
        tmp=tmp->suiv;
    }
    
    printf("Livre non trouvé par titre!\n");
    return NULL;
}
