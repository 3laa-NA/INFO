#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ArbreQuat.h"

void chaineCoordMinMax(Chaines* C, double* xmin, double* ymin, double* xmax, double* ymax){

    CellChaine *tmp_c = C->chaines;
    while(tmp_c){
        CellPoint *tmp_p = tmp_c->points;
        while(tmp_p){

            if(!xmin || *xmin > tmp_p->x){
                *xmin = tmp_p->x;
            }

            if(!xmax || *xmax < tmp_p->x){
                *xmax = tmp_p->x;
            }

            if(!ymin || *ymin > tmp_p->y){
                *ymin = tmp_p->y;
            }

            if(!ymax || *ymax < tmp_p->y){
                *ymax = tmp_p->y;
            }

            tmp_p = tmp_p->suiv;
        }
        tmp_c = tmp_c->suiv;
    }

}

ArbreQuat* creerArbreQuat(double xc, double yc, double coteX, double coteY){

    ArbreQuat *arb = (ArbreQuat*)malloc(sizeof(ArbreQuat));
    arb->xc = xc;
    arb->yc = yc;
    arb->coteX = coteX;
    arb->coteY = coteY;
    arb->noeud = NULL;
    arb->so = NULL;
    arb->se = NULL;
    arb->no = NULL;
    arb->ne = NULL;

    return arb; 
}

void insererNoeudArbre(Noeud* n, ArbreQuat** a, ArbreQuat* parent){

    // (cas arbre vide)
    if(!*a){

        //trouver les coordonnees de centre
        double xc , yc ;
        if(n->x < parent->xc){
            xc = parent->xc - (parent->coteX/4.0);
        }else{
            xc = parent->xc + (parent->coteX/4.0);
        }

        if(n->y < parent->yc){
            yc = parent->yc - (parent->coteY/4.0);
        }else{
            yc = parent->yc + (parent->coteY/4.0);
        }

        *a = creerArbreQuat(xc, yc, parent->coteX/2.0, parent->coteY/2.0); //on cree l'arbre et l'insere dans a
        
        (*a)->noeud = n;

        return;
    }

    //(cas feuille)
    if((*a)->noeud){

        Noeud *tmp = (*a)->noeud;
        
        (*a)->noeud = NULL; //on transforme la feuille en cellule interne
        
        insererNoeudArbre(n, a, parent); //on insere le nouveau n

        insererNoeudArbre(tmp, a, parent);

        return;
    }

    //else (cas cellule interne)
    
    if(n->x < (*a)->xc){ //on determine dans quelle sous arbre on doit continuer

        if(n->y < (*a)->yc){
            insererNoeudArbre(n, &(*a)->so, *a);
        }else{
            insererNoeudArbre(n, &(*a)->no, *a);
        }

    }else{

        if(n->y < (*a)->yc){
            insererNoeudArbre(n, &(*a)->se, *a);
        }else{
            insererNoeudArbre(n, &(*a)->ne, *a);
        }

    }

}


Noeud* rechercheCreeNoeudArbre(Reseau* R, ArbreQuat** a, ArbreQuat* parent, double x, double y){

    // (cas arbre vide)
    if(!*a){

        Noeud *n = (Noeud*)malloc(sizeof(Noeud));
        n->x = x;
        n->y = y;
        n->num = R->nbNoeuds++;

        CellNoeud *cn = (CellNoeud*)malloc(sizeof(CellNoeud));
        cn->nd = n;

        cn->suiv = R->noeuds;
        R->noeuds = cn;

        insererNoeudArbre(n, a, parent);

        return n;
    }

    //(cas feuille)
    if((*a)->noeud){

        if((*a)->noeud->x == x && (*a)->noeud->y == y){
            return (*a)->noeud;
        }

        Noeud *tmp = (*a)->noeud;
        
        (*a)->noeud = NULL; //on transforme la feuille en cellule interne
        
        insererNoeudArbre(n, a, parent); //on insere le nouveau n

        insererNoeudArbre(tmp, a, parent);

        return;
    }

    //else (cas cellule interne)
    
    if(n->x < (*a)->xc){ //on determine dans quelle sous arbre on doit continuer

        if(n->y < (*a)->yc){
            insererNoeudArbre(n, &(*a)->so, *a);
        }else{
            insererNoeudArbre(n, &(*a)->no, *a);
        }

    }else{

        if(n->y < (*a)->yc){
            insererNoeudArbre(n, &(*a)->se, *a);
        }else{
            insererNoeudArbre(n, &(*a)->ne, *a);
        }

    }
}