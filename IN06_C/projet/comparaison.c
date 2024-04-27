#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Hachage.h"
#include "ArbreQuat.h"


int main(){
    
    Chaines *cha;
    Reseau *res;

    for(int i = 1; i<11; i++){

        int nbch = i*5;

        cha = generationAleatoire(nbch, 10, 5000, 5000);

        clock_t debut, fin;

        /////////Liste-chainee/////////

        double t_ch = 0;

        debut = clock();
        
        res = reconstitueReseauListe(cha);

        fin = clock();

        t_ch = ((double) (fin - debut)) / CLOCKS_PER_SEC;

        libererReseau(res);

        /////////Arbre/////////
        
        double t_ar = 0;

        debut = clock();

        res = reconstitueReseauArbre(cha);
        
        fin = clock();

        t_ar = ((double) (fin - debut)) / CLOCKS_PER_SEC;

        libererReseau(res);


        /////////hachage/////////
        
        double t_h = 0;

        for(int n = 6; n<21; n++){

            debut = clock();

            res = reconstitueReseauHachage(cha, n);
            
            fin = clock();

            t_h += ((double) (fin - debut)) / CLOCKS_PER_SEC;

            libererReseau(res);

        }

        t_h /= 15;

        libererChaine(cha);

        FILE *res = fopen("comp.txt","a");

        fprintf(res, "%d %f %f %f\n", nbch,t_ch, t_h, t_ar);

        fclose(res);

    }

    return 0;
}