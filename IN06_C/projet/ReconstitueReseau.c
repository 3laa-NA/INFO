#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Hachage.h"
#include "ArbreQuat.h"

int main(){

    int rep;
    char input[256];
    FILE *fich;

    do{ //demander le nom de fichier
        
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

    do{ //afficher le menu avec les 3 choix
        
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
        
    Chaines *cha = lectureChaines(fich);
    fclose(fich);

    switch (m){

        case 1: ;

            Reseau *res = reconstitueReseauListe(cha);

            FILE *fich2 = fopen("Test_ch.res","w");

            ecrireReseau(res, fich2);

            fclose(fich2);

            afficheReseauSVG(res, "Test_ch_affich");

            libererReseau(res);

            break;

        case 2: ;

            Reseau *res_h = reconstitueReseauHachage(cha, 10);

            FILE *fich2_h = fopen("Test_h.res","w");

            ecrireReseau(res_h, fich2_h);

            fclose(fich2_h);

            afficheReseauSVG(res_h, "Test_h_affich");

            libererReseau(res_h);

            break;

        case 3: ;

            Reseau *res_ar = reconstitueReseauArbre(cha);

            FILE *fich2_ar = fopen("Test_ar.res","w");

            ecrireReseau(res_ar, fich2_ar);

            fclose(fich2_ar);

            afficheReseauSVG(res_ar, "Test_ar_affich");

            libererReseau(res_ar);

            break;

        default:
            break;

    }

    libererChaine(cha);

    return 0;
}
