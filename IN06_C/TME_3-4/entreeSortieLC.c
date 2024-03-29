#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "entreeSortieLC.h"

Biblio* charger_n_entrees(char* nomfic, int n){
    
    Biblio* b = creer_biblio(); 
    FILE *fichier = fopen(nomfic, "r");

    for(int i=0; i<n; i++){
        char titre[200]; char auteur[200] ; int num;

        int j = fscanf(fichier, "%d %s %s", &num, titre, auteur);

        if (j == 3) {
            inserer_en_tete(b, num, titre, auteur);

        } else {
            printf("Erreur lors de la lecture de la ligne %d\n", i+1);
        }

    }
    
    fclose(fichier);

    return b;
}

void enregistrer_biblio(Biblio *b, char* nomfic){

    FILE *fichier = fopen(nomfic, "w");
    Livre *l = b->L;

    while(l){
        fprintf(fichier,"%d %s %s\n", l->num, l->titre, l->auteur);
        l=l->suiv;
    }
    
    fclose(fichier);
}

