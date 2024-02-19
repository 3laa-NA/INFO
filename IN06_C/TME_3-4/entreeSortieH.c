#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "entreeSortieH.h"

BiblioH* charger_n_entrees(char* nomfic, int n){
    
    BiblioH* b = creer_biblio(100); 
    FILE *fichier = fopen(nomfic, "r");

    for(int i=0; i<n; i++){
        char titre[200]; char auteur[200] ; int num;

        int j = fscanf(fichier, "%d %s %s", &num, titre, auteur);

        if (j == 3) {
            inserer(b, num, titre, auteur);

        } else {
            printf("Erreur lors de la lecture de la ligne %d\n", i+1);
        }

    }
    
    fclose(fichier);

    return b;
}

void enregistrer_biblio(BiblioH *b, char* nomfic){

    FILE *fichier = fopen(nomfic, "w");
    for(int i=0; i<b->m; i++){
        LivreH *l = b->T[i];

        while(l){
            fprintf(fichier,"%d %s %s\n", l->num, l->titre, l->auteur);
            l=l->suivant;
        }
    }
    
    fclose(fichier);
}