#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Chaine.h"
#include "SVGwriter.h"


Chaines* lectureChaine(FILE *f){
    Chaines *ch = (Chaines*)malloc(sizeof(Chaines));

    char input[256];
    fgets(input, sizeof(input), f);
    sscanf(input,"NbChain: %d",&(ch->nbChaines));
    fgets(input, sizeof(input), f);
    sscanf(input,"Gamma: %d",&(ch->gamma));

    while(!feof(f)){
        fgets(input, sizeof(input), f);

        if(strcmp(input,"\n")==0){
            continue;
        }

        CellChaine *cch = (CellChaine*)malloc(sizeof(CellChaine));

        int n;
        sscanf(input,"%d %d",&(cch->numero), &n);

        int pos = 0;
        for (int i = 0; i < 2; i++) {
            pos += strcspn(input + pos, " ") + 1;
        }

        for (int i = 0; i < n; i++){
            CellPoint *cp = (CellPoint*)malloc(sizeof(CellPoint));
            float x, y;
            sscanf(input+pos, "%f %f", &x, &y);
            for (int i = 0; i < 2; i++) {
                pos += strcspn(input + pos, " ") + 1;
            }
            cp->x = x;
            cp->y = y;
            cp->suiv = cch->points;
            cch->points = cp;
        }

        cch->suiv = ch->chaines;
        ch->chaines = cch;
    }

    return ch;
}


void ecrireChaine(Chaines *C, FILE *f){
    fprintf(f, "NbChain: %d\nGamma: %d\n", C->nbChaines, C->gamma);

    CellChaine *tmp_c = C->chaines;
    while(tmp_c){

        fprintf(f, "%d", tmp_c->numero);
        
        CellPoint *tmp_p = tmp_c->points;

        int n_p = 0;
        char pts[256] = "";

        while(tmp_p){

            sprintf(pts + strlen(pts), " %.2f %.2f", tmp_p->x, tmp_p->y);

            n_p++;
            tmp_p = tmp_p->suiv;
        }

        fprintf(f, " %d%s\n", n_p, pts);

        tmp_c = tmp_c->suiv;
    }
}


void afficheChainesSVG(Chaines *C, char* nomInstance){
    //int i;
    double maxx=0,maxy=0,minx=1e6,miny=1e6;
    CellChaine *ccour;
    CellPoint *pcour;
    double precx,precy;
    SVGwriter svg;
    ccour=C->chaines;
    while (ccour!=NULL){
        pcour=ccour->points;
        while (pcour!=NULL){
            if (maxx<pcour->x) maxx=pcour->x;
            if (maxy<pcour->y) maxy=pcour->y;
            if (minx>pcour->x) minx=pcour->x;
            if (miny>pcour->y) miny=pcour->y;  
            pcour=pcour->suiv;
        }
    ccour=ccour->suiv;
    }
    SVGinit(&svg,nomInstance,500,500);
    ccour=C->chaines;
    while (ccour!=NULL){
        pcour=ccour->points;
        SVGlineRandColor(&svg);
        SVGpoint(&svg,500*(pcour->x-minx)/(maxx-minx),500*(pcour->y-miny)/(maxy-miny)); 
        precx=pcour->x;
        precy=pcour->y;  
        pcour=pcour->suiv;
        while (pcour!=NULL){
            SVGline(&svg,500*(precx-minx)/(maxx-minx),500*(precy-miny)/(maxy-miny),500*(pcour->x-minx)/(maxx-minx),500*(pcour->y-miny)/(maxy-miny));
            SVGpoint(&svg,500*(pcour->x-minx)/(maxx-minx),500*(pcour->y-miny)/(maxy-miny));
            precx=pcour->x;
            precy=pcour->y;    
            pcour=pcour->suiv;
        }
        ccour=ccour->suiv;
    }
    SVGfinalize(&svg);
}


double longueurChaine(CellChaine *c){

    double res = 0;
    if(!c->points){
        return res;
    }

    CellPoint *tmp = c->points;
    while(tmp->suiv){
        res+= sqrt(pow(tmp->suiv->x - tmp->x, 2) + pow(tmp->suiv->y - tmp->y, 2));

        tmp = tmp->suiv;
    }

    return res;
}



double longueurTotale(Chaines *C){

    double res = 0;
    CellChaine *tmp = C->chaines;

    while(tmp){
        res+= longueurChaine(tmp);

        tmp = tmp->suiv;
    }

    return res;
}


int comptePointsTotal(Chaines *C){
    
    int res = 0;

    CellChaine *tmp_c = C->chaines;
    while(tmp_c){
        CellPoint *tmp_p = tmp_c->points;
        while(tmp_p){
            res++;
        }
    }
    
    return res;
}


