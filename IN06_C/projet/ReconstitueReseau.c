#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Hachage.h"

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

            ecrireReseau(res, fich2);

            fclose(fich2);

            afficheReseauSVG(res, "test");

            break;

        case 2: ;
            Chaines *cha_h = lectureChaines(fich);
            
            fclose(fich);

            Reseau *res_h = reconstitueReseauHachage(cha_h, 10);

            FILE *fich2_h = fopen("Test.res","w");

            ecrireReseau(res_h, fich2_h);

            fclose(fich2_h);

            afficheReseauSVG(res_h, "test");

            break;

        case 3: ;
            printf("3\n");

            break;

        default:
            break;

    }
    

    return 0;
}
