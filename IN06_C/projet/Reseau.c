#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Reseau.h"

Noeud* rechercheCreeNoeudListe(Reseau *R, double x, double y){

    CellNoeud *tmp_cn = R->noeuds;
    while(tmp_cn){
        if(tmp_cn->nd->x == x && tmp_cn->nd->y == y){
            return tmp_cn->nd;
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
        Noeud *A, *B; //les extrémités

        Noeud *n_prec; //le noeud precedent(pour mettre à jour les voisins)

        while(tmp_p){

            Noeud* tmp_n = rechercheCreeNoeudListe(R, tmp_p->x, tmp_p->y);

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