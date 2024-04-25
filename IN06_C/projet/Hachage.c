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

    int cle = fonctionClef(x, y);
    int i = fonctionHachage(cle,H->tailleMax); //on trouve l'indice

    CellNoeud *tmp_cn = H->T[i];

    while(tmp_cn){ //on cherche dans le tableau de hachage

        if(tmp_cn->nd->x==x && tmp_cn->nd->y==y){
            return tmp_cn->nd;
        }
        tmp_cn = tmp_cn->suiv;
    }
    
    //sinon on cree
    Noeud *nd = (Noeud*)malloc(sizeof(Noeud));
    nd->x = x;
    nd->y = y;
    nd->num = R->nbNoeuds+1;
    nd->voisins = NULL;

   //on ajoute dans le tableau de hachage 
    CellNoeud *cn = (CellNoeud*)malloc(sizeof(CellNoeud));
    cn->nd = nd;
    cn->suiv = H->T[i];
    H->T[i] = cn;

    //on ajoute dans le reseau
    CellNoeud *cn2 = (CellNoeud*)malloc(sizeof(CellNoeud));
    cn2->nd = nd;
    cn2->suiv = R->noeuds;
    R->noeuds = cn2;
    R->nbNoeuds++;

    return nd;
}

Reseau* reconstitueReseauHachage(Chaines *C, int M){

    Reseau *R = (Reseau*)malloc(sizeof(Reseau)); //allocation du reseau et initialisation des valeurs
    R->nbNoeuds = 0;
    R->gamma = C->gamma;
    R->noeuds = NULL;
    R->commodites = NULL;

    TableHachage *H = (TableHachage*)malloc(sizeof(TableHachage)); //allocation du tableau de hachage
    H->nbElement = 0;
    H->tailleMax = M;
    H->T = (CellNoeud**)malloc(sizeof(CellNoeud*) * M);
    for(int i = 0; i < M; i++) {
        H->T[i] = NULL;
    }


    CellChaine *tmp_cch = C->chaines;
    while(tmp_cch){ //on parcourt les chaines

        CellPoint *tmp_p = tmp_cch->points;
        Noeud *A = NULL; Noeud *B = NULL; //les extrémités

        Noeud *n_prec = NULL; //le noeud precedent(pour mettre à jour les voisins)

        while(tmp_p){

            Noeud* tmp_n = rechercheCreeNoeudHachage(R, H, tmp_p->x, tmp_p->y);

            if(!A){//on stock la premiere extrémité
                A = tmp_n;
            }
            if(!tmp_p->suiv){//ici la deuxieme
                B = tmp_n;
            }


            if(n_prec){

                CellNoeud *voisins_prec = n_prec->voisins;
                while(voisins_prec){ //on verifie si les 2 noeuds sont deja enregistrés comme des voisins
                    if(voisins_prec->nd == tmp_n){
                        break;
                    }
                    voisins_prec = voisins_prec->suiv;
                }
                

                if(!voisins_prec){ //on met à jour les listes des voisins
                    CellNoeud *tmp_v = (CellNoeud*)malloc(sizeof(CellNoeud));
                    tmp_v->nd = tmp_n;
                    tmp_v->suiv = n_prec->voisins;
                    n_prec->voisins = tmp_v;

                    CellNoeud *tmp_v1 = (CellNoeud*)malloc(sizeof(CellNoeud));
                    tmp_v1->nd = n_prec;
                    tmp_v1->suiv = tmp_n->voisins;
                    tmp_n->voisins = tmp_v1;
                }
            }

            n_prec = tmp_n;

            tmp_p = tmp_p->suiv;
        }

        CellCommodite *CC = (CellCommodite*)malloc(sizeof(CellCommodite));
        CC->extrA = A;
        CC->extrB = B;
        CC->suiv = R->commodites;

        R->commodites = CC;

        tmp_cch = tmp_cch->suiv;
    }

    return R;
}


/*
int main(){
    
    for(int x = 1; x<11; x++){
        for(int y = 1; y<11; y++){
            printf("%d ",fonctionClef(x,y));
        }
    }

    return 0;
}
*/