#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Reseau.h"

Noeud* rechercheCreeNoeudListe(Reseau *R, double x, double y){

    CellNoeud *tmp_cn = R->noeuds;
    while(tmp_cn){
        if(tmp_cn->nd->x == x && tmp_cn->nd->y == y){
            return tmp_cn;
        }
        tmp_cn = tmp_cn->suiv;
    }

    Noeud *res = (Noeud*)malloc(sizeof(Noeud));
    res->x = x;
    res->y = y;
    res->num = R->nbNoeuds+1;  

    CellNoeud *CN = (CellNoeud*)malloc(sizeof(CellNoeud));
    CN->nd = res;
    CN->suiv = R->noeuds;

    R->noeuds = CN;
    R->nbNoeuds++;

    return res;
}

Reseau* reconstitueReseauListe(Chaines *C){

    Reseau *R = (Reseau*)malloc(sizeof(Reseau));
    R->nbNoeuds = 0;
    R->gamma = C->gamma;  

    CellChaine *tmp_cch = C->chaines;
    while(tmp_cch){

        CellPoint *tmp_p = tmp_cch->points;
        Noeud *A, *B;

        while(tmp_p){

            Noeud* tmp_n = rechercheCreeNoeudListe(R, tmp_p->x, tmp_p->y);

            if(!A){//on stock le premier extrimité
                A = tmp_n;
            }
            if(!tmp_p->suiv){//ici le deuxieme
                B = tmp_n;
            }

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