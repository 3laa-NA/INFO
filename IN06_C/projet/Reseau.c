#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Reseau.h"
#include "SVGwriter.h"

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
    R->noeuds = NULL;
    R->commodites = NULL;

    CellChaine *tmp_cch = C->chaines;
    while(tmp_cch){

        CellPoint *tmp_p = tmp_cch->points;
        Noeud *A = NULL; Noeud *B = NULL; //les extrémités

        Noeud *n_prec = NULL; //le noeud precedent(pour mettre à jour les voisins)


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


int nbLiaisons(Reseau *R){
    int res = 0;
    CellNoeud *tmp_n = R->noeuds;

    while(tmp_n){

        CellNoeud *tmp_v = tmp_n->nd->voisins;
        while(tmp_v){
            res++;
            tmp_v = tmp_v->suiv;
        }

        tmp_n = tmp_n->suiv;
    }

    return res/2;
}


int nbCommodites(Reseau *R){
    int res = 0;

    CellCommodite *tmp_c = R->commodites;

    while(tmp_c){
        res++;
        tmp_c = tmp_c->suiv;
    }

    return res;
}


void ecrireReseau(Reseau *R, FILE *f){

    fprintf(f, "NbNoeuds: %d\nNbLiaisons: %d\nNbCommodites: %d\nGamma: %d\n\n", R->nbNoeuds, nbLiaisons(R), nbCommodites(R), R->gamma);

    CellNoeud *tmp_n = R->noeuds;

    char lia[256] = "";

    while(tmp_n){

        fprintf(f, "v %d %.2f %.2f\n", tmp_n->nd->num, tmp_n->nd->x, tmp_n->nd->y);

        CellNoeud *tmp_v = tmp_n->nd->voisins;

        while(tmp_v){
            sprintf(lia + strlen(lia), "l %d %d\n", tmp_v->nd->num, tmp_n->nd->num);
            tmp_v = tmp_v->suiv;
        }

        tmp_n = tmp_n->suiv;

    }

    fprintf(f, "\n%s\n", lia);

    CellCommodite *tmp_c = R->commodites;
    while(tmp_c){

        fprintf(f, "k %d %d\n", tmp_c->extrA->num, tmp_c->extrB->num);
        tmp_c = tmp_c->suiv;
    }

}


void afficheReseauSVG(Reseau *R, char* nomInstance){
    CellNoeud *courN,*courv;
    SVGwriter svg;
    double maxx=0,maxy=0,minx=1e6,miny=1e6;

    courN=R->noeuds;
    while (courN!=NULL){
        if (maxx<courN->nd->x) maxx=courN->nd->x;
        if (maxy<courN->nd->y) maxy=courN->nd->y;
        if (minx>courN->nd->x) minx=courN->nd->x;
        if (miny>courN->nd->y) miny=courN->nd->y;
        courN=courN->suiv;
    }
    SVGinit(&svg,nomInstance,500,500);
    courN=R->noeuds;
    while (courN!=NULL){
        SVGpoint(&svg,500*(courN->nd->x-minx)/(maxx-minx),500*(courN->nd->y-miny)/(maxy-miny));
        courv=courN->nd->voisins;
        while (courv!=NULL){
            if (courv->nd->num<courN->nd->num)
                SVGline(&svg,500*(courv->nd->x-minx)/(maxx-minx),500*(courv->nd->y-miny)/(maxy-miny),500*(courN->nd->x-minx)/(maxx-minx),500*(courN->nd->y-miny)/(maxy-miny));
            courv=courv->suiv;
        }
        courN=courN->suiv;
    }
    SVGfinalize(&svg);
}

