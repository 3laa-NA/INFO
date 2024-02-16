#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "entreeSortieLC.c"

/*int main(int argc, char const *argv[]){

    char * titre = "ch";
    Livre* l = creer_livre(05,titre,"mo");
    titre = "hello";
    printf("%d %s %s  %s\n", l->num,l->titre , l-> auteur,titre);
    return 0;
}*/


int main(int argc, char** argv){
    if(argc < 3){
        printf("arguments manquantes!\n");
        return 0;
    }
    
    Biblio *b = charger_n_entrees(argv[1],atoi(argv[2]));
    afficher_biblio(b);

    Livre *l3 = recherche_livre_num(b,8);
    afficher_livre(l3);

    Livre *l4 = recherche_livre_titre(b,"JYBLD");
    afficher_livre(l4);

    return 0;
}