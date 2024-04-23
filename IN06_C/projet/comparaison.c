#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Hachage.h"
#include "ArbreQuat.h"


int main(){
    
    Chaines *cha;

    for(int nbCh = 1; nbCh<11; nbCh++){

        cha = generationAleatoire(nbCh*5, 10, 50, 50);

        clock_t debut, fin;

        /////////Liste-chainee/////////

        double t_ch = 0;

        debut = clock();
        printf("avan\nt");
        reconstitueReseauListe(cha);
        reconstitueReseauListe(cha);
        printf("apres\n");

        fin = clock();

        t_ch = ((double) (fin - debut)) / CLOCKS_PER_SEC;

        /////////Arbre/////////
        
        double t_ar = 0;

        debut = clock();

        reconstitueReseauArbre(cha);
        
        fin = clock();

        t_ar = ((double) (fin - debut)) / CLOCKS_PER_SEC;


        /////////hachage/////////
        
        double t_h = 0;

        for(int n = 6; n<21; n++){

            debut = clock();

            reconstitueReseauHachage(cha, n);
            
            fin = clock();

            t_h += ((double) (fin - debut)) / CLOCKS_PER_SEC;

        }

        t_h /= 15;



        FILE *res = fopen("resultats_de_comp.txt","a");

        fprintf(res, "List: %f Hachage: %f Arbre: %f\n", t_ch, t_h, t_ar);

        fclose(res);

    }

    return 0;
}