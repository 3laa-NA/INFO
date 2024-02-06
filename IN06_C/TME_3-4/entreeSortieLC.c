#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entreeSortieLC.h"

Biblio* charger_n_entrees(char* nomfic, int n){
    
    Biblio* b = creer_biblio(); 
    FILE *fichier = fopen("test_str.txt", "w");

    for(int i=0; i<n; i++){
        char *titre, *auteur ; int num;
        
        if (fscanf(fichier, "%d %s %s", &num, titre, auteur) == 3) {
            inserer_en_tete(b, num, titre, auteur);
        } else {
            printf("Erreur lors de la lecture de la ligne %d\n", i + 1);
        }

    }
    
    fclose(fichier);

    return b;
}

void enregistrer_biblio(Biblio *b, char* nomfic){

    FILE *fichier = fopen("test_str.txt", "r");
    Livre *l = b->L;

    while(l){
        printf("%d %s %s\n", l->num, l->titre, l->auteur);
        l=l->suiv;
    }
    
    fclose(fichier);
}

