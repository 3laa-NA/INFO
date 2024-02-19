#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "biblioH.h"

int fonctionClef(char* auteur){
    int res=0;
    for(int i=0; i<(int)(strlen(auteur)); i++){
        res+=auteur[i];
    }

    return res;
}

LivreH* creer_livre(int num,char* titre,char* auteur){
    LivreH* new = (LivreH*)malloc(sizeof(LivreH));

    new->clef = fonctionClef(auteur);
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
    
    LivreH *l = creer_livre(num,titre,auteur);
    int i = fonctionHachage(l->clef,b->m);

    l->suivant = b->T[i];

    b->T[i] = l;
    b->nE++;
}



void afficher_livre(LivreH *l){
    if(l){
        printf("\nLivre numéro: %d\n   Titre: %s\n   Auteur: %s\n",l->num,l->titre,l->auteur);
    }
}



void afficher_biblio(BiblioH *b){
    if(!b->nE){
        printf("\nLe biblioH est vide!\n");
        return;
    }

    printf("\nLa biblioH contient %d livreH(s), le(s) voilà:\n",b->nE);
    for(int i=0; i<b->m; i++){
        LivreH *l = b->T[i];

        while(l){
            afficher_livre(l);
            l=l->suivant;
        }
    }

}



LivreH *recherche_livre_num(BiblioH *b,int n){
    
    if(!b->nE){
        printf("\nLe biblioH est vide!\n");
        return NULL;
    }

    for(int i=0; i<b->m; i++){
        LivreH *l = b->T[i];

        while(l){
            if(l->num == n){
                printf("\nLivre trouvé!\n");
                return l;
            }
            l=l->suivant;
        }
    }
    
    printf("\nLivre non trouvé par numéro!\n");
    return NULL;
}



LivreH *recherche_livre_titre(BiblioH *b,char *titre){

    if(!b->nE){
        printf("\nLe biblioH est vide!\n");
        return NULL;
    }

    for(int i=0; i<b->m; i++){
        LivreH *l = b->T[i];

        while(l){
            if(!strcmp(l->titre,titre)){
                printf("\nLivre trouvé!\n");
                return l;
            }
            l=l->suivant;
        }
    }
    
    printf("\nLivre non trouvé par titre!\n");
    return NULL;
}



BiblioH *recherche_livres_auteur(BiblioH *b,char *auteur){

    if(!b->nE){
        printf("\nLe biblioH est vide!\n");
        return NULL;
    }
    
    BiblioH *res = NULL;

    int i = fonctionHachage(fonctionClef(auteur),b->m);
    LivreH *l = b->T[i];

    while(l){
        if(!strcmp(l->auteur,auteur)){
            if(!res){ //on fait en sorte que la biblioH ne soit pas créée à moins qu'on a trouvé un livreH
                res = creer_biblio(1); //meme auteur donc meme clef pas une biblioH comme cela suffit
            }
            inserer(res,l->num,l->titre,l->auteur);
        }
        l=l->suivant;
    }
    
    return res;
}



int supprimer_livre(BiblioH* b,int num,char* titre,char* auteur){

    if(!b->nE){
        printf("\nLe biblioH est vide!\n");
        return 0;
    }


    int i = fonctionHachage(fonctionClef(auteur),b->m);
    LivreH *tmp = b->T[i];
        
    if(tmp->num==num && !strcmp(tmp->titre,titre) && !strcmp(tmp->auteur,auteur)){
        b->T[i]=tmp->suivant;
        liberer_livre(tmp);

        return 1;
    }
    
    LivreH *s; //livreH suivant
    
    while(tmp){
        s = tmp->suivant;

        if(!s){
            return 0;
        }

        if(s->num==num && !strcmp(s->titre,titre) && !strcmp(s->auteur,auteur)){
            tmp->suivant=s->suivant;
            liberer_livre(s);

            return 1;
        }
        tmp=tmp->suivant;
    }

    return 0;
    
}



void fusion(BiblioH *b1, BiblioH *b2){

    for(int i=0; i<b2->m; i++){
        LivreH *l = b2->T[i];

        while(l){
            inserer(b1, l->num, l->titre, l->auteur);
            l=l->suivant;
        }
    }

    liberer_biblio(b2);

}



LivreH *dupliques(BiblioH *b){

    LivreH *res = NULL;

    for(int i=0; i<b->m; i++){

        LivreH *tmp = b->T[i];
        
        while(tmp){

            LivreH *tmp2 = tmp->suivant;
            int d=0; //indique si le livreH dupliqué est déja dans 'res'

            while(tmp2){

                if(!strcmp(tmp2->titre,tmp->titre) && !strcmp(tmp2->auteur,tmp->auteur) ){

                    if(!d){ //on doit ajouter tout les exemplaires!!
                        LivreH* l = creer_livre(tmp->num,tmp->titre,tmp->auteur);
                        l->suivant = res;
                        res = l;
                        supprimer_livre(b, tmp->num, tmp->titre, tmp->auteur);
                        d++;
                    }

                    LivreH* l2 = creer_livre(tmp2->num,tmp2->titre,tmp2->auteur);
                    l2->suivant = res;
                    res = l2;
                    supprimer_livre(b, tmp2->num, tmp2->titre, tmp2->auteur);
                    
                }

                tmp2=tmp2->suivant;
            }

            tmp=tmp->suivant;
        }

    }


    return res;
}
