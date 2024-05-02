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

        int nbch = i*50;
        int nbpts = nbch*100;

        cha = generationAleatoire(nbch, 100, 5000, 5000); //generer les chaines

        clock_t debut, fin;

        /////////Liste-chainee/////////

        double t_ch = 0; //temps pour les listes chainées

        debut = clock();
        
        res = reconstitueReseauListe(cha);

        fin = clock();

        t_ch = ((double) (fin - debut)) / CLOCKS_PER_SEC;

        libererReseau(res);

        /////////Arbre/////////
        
        double t_ar = 0; //temps pour l'arbre

        debut = clock();

        res = reconstitueReseauArbre(cha);
        
        fin = clock();

        t_ar = ((double) (fin - debut)) / CLOCKS_PER_SEC;

        libererReseau(res);


        /////////hachage/////////
        
        double t_h_quart = 0; //temps pour les tables d'hachage de taille nbpts/4

        debut = clock();

        res = reconstitueReseauHachage(cha, nbpts/4);
        
        fin = clock();

        t_h_quart = ((double) (fin - debut)) / CLOCKS_PER_SEC;

        libererReseau(res);
        

        double t_h_moitie = 0; //taille nbpts/2

        debut = clock();

        res = reconstitueReseauHachage(cha, nbpts/2);
        
        fin = clock();

        t_h_moitie = ((double) (fin - debut)) / CLOCKS_PER_SEC;

        libererReseau(res);


        double t_h = 0; //taille nbpts

        debut = clock();

        res = reconstitueReseauHachage(cha, nbpts);
        
        fin = clock();

        t_h = ((double) (fin - debut)) / CLOCKS_PER_SEC;

        libererReseau(res);


        double t_h_double = 0; //taille nbpts*2

        debut = clock();

        res = reconstitueReseauHachage(cha, nbpts*2);
        
        fin = clock();

        t_h_double = ((double) (fin - debut)) / CLOCKS_PER_SEC;

        libererReseau(res);


        double t_h_4 = 0; //taille nbpts*4

        debut = clock();

        res = reconstitueReseauHachage(cha, nbpts*4);
        
        fin = clock();

        t_h_4 = ((double) (fin - debut)) / CLOCKS_PER_SEC;


        libererReseau(res);


        libererChaine(cha);

        FILE *res = fopen("comp.txt","a"); //stocker les resultats dans comp.txt

        fprintf(res, "%d %f %f %f %f %f %f %f\n", nbch, t_ch, t_ar, t_h_quart, t_h_moitie, t_h, t_h_double, t_h_4);

        fclose(res);

    }

    return 0;
}