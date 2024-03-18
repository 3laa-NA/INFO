#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Reseau.h"

int main(){

    int rep;
    char input[256];
    FILE *fich;

    do{      
        
        printf("Veuillez ecrire le nom du fichier .cha (ou tapez 'quit' pour quitter): ");

        fgets(input, sizeof(input), stdin);

        input[strcspn(input, "\n")] = '\0';

        if(strcmp(input,"quit") == 0){
            return 0;
        }
        
        fich = fopen(input,"r");
        if (fich == NULL) {
            perror("erreur lors de l'ouverture du fichier(nom probablement incorrecte)! Réessayez!\n");
            rep = 1;
        }else{rep = 0;}

    }while(rep);

    int m; //methode

    do{      
        
        printf("Veuillez choisir la méthode souhaitée parmi les suivanetes:\n1.liste\n2.table de hachage\n3.arbre\n(ou tapez 'quit' pour quitter): ");

        fgets(input, sizeof(input), stdin);

        input[strcspn(input, "\n")] = '\0';

        if(strcmp(input,"quit") == 0){
            return 0;
        }

        m = atoi(input);
        
        if(!m || m > 3){
            printf("insertion non valide!\n");
            rep = 1;
        }else{rep = 0;}

    }while(rep);

    switch (m){

        case 1: ;
            Chaines *cha = lectureChaines(fich);
            
            fclose(fich);

            Reseau *res = reconstitueReseauListe(cha);

            FILE *fich2 = fopen("Test.res","w");

            printf("1\n");

            ecrireReseau(res, fich2);

            printf("2\n");

            fclose(fich2);

            printf("3\n");

            afficheReseauSVG(res, "test");

            printf("4\n");

            break;

        case 2: ;
            printf("2\n");

            break;

        case 3: ;
            printf("3\n");

            break;

        default:
            break;

    }
    

    return 0;
}
