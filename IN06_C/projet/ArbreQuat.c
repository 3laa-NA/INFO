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

            if(*xmin > tmp_p->x){
                *xmin = tmp_p->x;
            }

            if(*xmax < tmp_p->x){
                *xmax = tmp_p->x;
            }

            if(*ymin > tmp_p->y){
                *ymin = tmp_p->y;
            }

            if(*ymax < tmp_p->y){
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

        Noeud *n = (Noeud*)malloc(sizeof(Noeud)); //créer le noeud
        n->x = x;
        n->y = y;
        n->num = R->nbNoeuds+1;
        n->voisins = NULL;

        CellNoeud *cn = (CellNoeud*)malloc(sizeof(CellNoeud)); // créer la cellule
        cn->nd = n;

        cn->suiv = R->noeuds; // inserer dans le reseau
        R->noeuds = cn;
        R->nbNoeuds++;

        insererNoeudArbre(n, a, parent); //inserer dans le tableau

        return n;
    }

    //(cas feuille)
    if((*a)->noeud){

        if((*a)->noeud->x == x && (*a)->noeud->y == y){
            return (*a)->noeud;
        }

        Noeud *n = (Noeud*)malloc(sizeof(Noeud)); //créer le noeud
        n->x = x;
        n->y = y;
        n->num = R->nbNoeuds+1;
        n->voisins = NULL;

        CellNoeud *cn = (CellNoeud*)malloc(sizeof(CellNoeud)); // créer la cellule
        cn->nd = n;

        cn->suiv = R->noeuds; // inserer dans le reseau
        R->noeuds = cn;
        R->nbNoeuds++;

        insererNoeudArbre(n, a, parent); //inserer dans le tableau

        return n;
    }

    //else (cas cellule interne)
    
    if(x < (*a)->xc){ //on determine dans quelle sous arbre on doit continuer

        if(y < (*a)->yc){
            return rechercheCreeNoeudArbre(R, &(*a)->so, *a, x, y);
        }else{
            return rechercheCreeNoeudArbre(R, &(*a)->no, *a, x, y);
        }

    }else{

        if(y < (*a)->yc){
            return rechercheCreeNoeudArbre(R, &(*a)->se, *a, x, y);
        }else{
            return rechercheCreeNoeudArbre(R, &(*a)->ne, *a, x, y);
        }

    }
}

Reseau* reconstitueReseauArbre(Chaines* C){
    Reseau *R = (Reseau*)malloc(sizeof(Reseau)); //allocation du reseau et initialisation des valeurs
    R->nbNoeuds = 0;
    R->gamma = C->gamma;
    R->noeuds = NULL;
    R->commodites = NULL;

    double xmin = 0, ymin = 0, xmax = 0, ymax = 0;
    chaineCoordMinMax(C, &xmin, &ymin, &xmax, &ymax);

    double coteX = xmax - xmin;
    double coteY = ymax - ymin;
    double xc = xmin + (coteX/2);
    double yc = ymin + (coteY/2);
    ArbreQuat *AR = creerArbreQuat(xc, yc, coteX, coteY); //creation de l'arbre

    CellChaine *tmp_cch = C->chaines;
    while(tmp_cch){ //on parcourt les chaines

        CellPoint *tmp_p = tmp_cch->points;
        Noeud *A = NULL; Noeud *B = NULL; //les extrémités

        Noeud *n_prec = NULL; //le noeud precedent(pour mettre à jour les voisins)


        while(tmp_p){ //on parcourt les points de la chaine

            Noeud* tmp_n = rechercheCreeNoeudArbre(R, &AR, AR, tmp_p->x, tmp_p->y);

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

