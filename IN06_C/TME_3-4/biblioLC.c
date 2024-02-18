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
    free(l->titre);
    free(l->auteur);

    free (l);
}



Biblio* creer_biblio(){
    Biblio* b = (Biblio*)malloc(sizeof(Biblio));
    b->L = NULL;

    return b;
}



void liberer_biblio(Biblio* b){
    while(b->L){
        Livre *tmp = b->L;
        b->L = tmp->suiv;
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
    if(l){
        printf("\nLivre numéro: %d\n   Titre: %s\n   Auteur: %s\n",l->num,l->titre,l->auteur);
    }
}



void afficher_biblio(Biblio *b){
    Livre *tmp = b->L;
    if(tmp){
        printf("\nLa biblio contient le(s) livre(s) suivants:\n");
    }else{
        printf("\nLe biblio est vide!\n");
    }
    while(tmp){
        afficher_livre(tmp);
        tmp = tmp->suiv;
    }
}



Livre *recherche_livre_num(Biblio *b,int n){
    Livre *tmp = b->L;
    if(!tmp){
        printf("\nLe biblio est vide!\n");
        return NULL;
    }
    while(tmp){
        if(tmp->num == n){
            printf("\nLivre trouvé!\n");
            return tmp;
        }
        tmp=tmp->suiv;
    }
    
    printf("\nLivre non trouvé par numéro!\n");
    return NULL;
}



Livre *recherche_livre_titre(Biblio *b,char *titre){
    Livre *tmp = b->L;
    if(!tmp){
        printf("\nLe biblio est vide!\n");
        return NULL;
    }
    while(tmp){
        if(!strcmp(tmp->titre,titre)){
            printf("\nLivre trouvé!\n");
            return tmp;
        }
        tmp=tmp->suiv;
    }
    
    printf("\nLivre non trouvé par titre!\n");
    return NULL;
}



Biblio *recherche_livres_auteur(Biblio *b,char *auteur){

    Livre *tmp = b->L;

    if(!tmp){
        printf("\nLe biblio est vide!\n");
        return NULL;
    }

    Biblio *res = NULL;

    while(tmp){
        if(!strcmp(tmp->auteur,auteur)){
            if(!res){ //on fait en sorte que la biblio ne soit pas créée à moins qu'on a trouvé un livre
                res = creer_biblio();
            }
            inserer_en_tete(res,tmp->num,tmp->titre,tmp->auteur);
        }
        tmp=tmp->suiv;
    }
    
    return res;
}



void supprimer_livre(Biblio* b,int num,char* titre,char* auteur){

    Livre *tmp = b->L;

    if(!tmp){
        printf("\nLe biblio est vide!\n");
        return ;
    }

    if(tmp->num==num && !strcmp(tmp->titre,titre) && !strcmp(tmp->auteur,auteur)){
        b->L=tmp->suiv;
        liberer_livre(tmp);

        printf("\nLivre supprimé!\n");
        return ;
    }
    
    Livre *s; //livre suivant
    
    while(tmp){
        s = tmp->suiv;

        if(!s){
            printf("\nLivre non trouvé!\n");
            return;
        }

        if(s->num==num && !strcmp(s->titre,titre) && !strcmp(s->auteur,auteur)){
            tmp->suiv=s->suiv;
            liberer_livre(s);

            printf("\nLivre supprimé!\n");
            return ;
        }
        tmp=tmp->suiv;
    }
    
}



void fusion(Biblio *b1, Biblio *b2){

    Livre *tmp = b1->L;
    while(tmp->suiv){
        tmp=tmp->suiv;
    }

    tmp->suiv = b2->L;
    b2->L = NULL;
    liberer_biblio(b2);

}



Livre *dupliques(Biblio *b){

    Livre *tmp = b->L;
    Livre *res = NULL;

    while(tmp){

        Livre *tmp2 = tmp->suiv;
        int d=0; //indique si le livre dupliqué est déja dans 'res'

        while(tmp2){

            if(!strcmp(tmp2->titre,tmp->titre) && !strcmp(tmp2->auteur,tmp->auteur) ){

                if(!d){ //on doit ajouter tout les exemplaires!!
                    Livre* l = creer_livre(tmp->num,tmp->titre,tmp->auteur);
                    l->suiv = res;
                    res = l;
                }

                Livre* l = creer_livre(tmp2->num,tmp2->titre,tmp2->auteur);
                l->suiv = res;
                res = l;

            }

            tmp2=tmp2->suiv;
        }

        tmp=tmp->suiv;
    }

    return res;
}