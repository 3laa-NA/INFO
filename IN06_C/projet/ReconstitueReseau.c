#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Reseau.h"

int main(){

    int rep;

    do{      
        
        char input[256];
        printf("Veuillez ecrire le nom du fichier .cha: ");

        fgets(input, sizeof(input), stdin);
        
        FILE *fich = fopen(input,"r");
        if (fich == NULL) {
            perror("erreur lors de l'ouverture du fichier(nom probablement incorrecte)! Réessayez!\n");
            rep = 1;
        }else{rep = 0;}

    }while(rep);
    
    rep = atoi(input);
    
    do{

        

        printf("\n");
        if(!rep && strcmp(input,"0\n")){
            printf("ceci n'est pas un numéro!!\n");
            rep=100;
        }

        switch (atoi(argv[2])) {

            case 0:
                break;

            default:
                printf("veuillez choisir un des numéros aux quelles est associé une action!\n\n");
                break;
        }

    }while(rep);

    Chaines *res = lectureChaine(fich);
    
    fclose(fich);

    FILE *fich2 = fopen("Test","w");

    ecrireChaine(res, fich2);

    fclose(fich2);

    afficheChainesSVG(res, "test");


    return 0;
}



