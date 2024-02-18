#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "biblioLC.h"
#include "entreeSortieLC.h"

void menu(){
    printf("\nACTIONS POSSIBLES: \n0-sortie du programme \n1-Affichage \n2-Inserer ouvrage \n3-Supprimer un ouvrage \n4-rechercher un ouvrage par numéro \n5-rechercher un ouvrage par titre \n6-rechercher les ouvrages d'un auteur \n7-afficher les livres dupliqués(tout les exemplaire) \n\n");
}

int main(int argc, char** argv){
    if(argc < 3){
        printf("arguments manquantes!\n");
        return 0;
    }
    
    Biblio *b = charger_n_entrees(argv[1],atoi(argv[2]));

    int rep;
    do{

        char input[256];
        menu();

        fgets(input, sizeof(input), stdin);
        rep = atoi(input);

        printf("\n");
        if(!rep && strcmp(input,"0\n")){
            printf("ceci n'est pas un numéro!!\n");
            rep=100;
        }

        switch (rep) {

        case 0:
            break;
            
        case 1:
            printf ("Affichage: \n");
            afficher_biblio(b);
            break;

        case 2: ;

            char num [256];
            char titre [256];
            char auteur [256];

            int indicateur;
            do{
                indicateur=0;

                printf ("Veuillez ecrire le numéro de l’ouvrage à ajouter ou écrivez 'retour' pour revenir à la liste d'actions.\n\n");
                fgets (num,sizeof(num), stdin);
                if(!strcmp(num,"retour\n")){
                    indicateur=1;
                    break;
                }
                if(!atoi(num) && strcmp(num,"0\n")){
                    printf("\nceci n'est pas un numéro!!\nRéessayez!\n");
                    indicateur=1;
                }

            }while(indicateur);//pour rester dans la boucle tant que la valeur est invalide
            if(indicateur){break;}//pour revenir à la list d'action

            printf ("\nVeuillez ecrire le titre de l’ouvrage.\n\n");
            fgets (titre,sizeof(titre), stdin);
            titre[strlen(titre)-1] = '\0';

            printf ("\nVeuillez ecrire le nom de l’auteur de l’ouvrage.\n\n");
            fgets (auteur,sizeof(auteur), stdin);
            auteur[strlen(auteur)-1] = '\0';

            inserer_en_tete (b , atoi(num) , titre , auteur );
            printf ("\nAjout fait.\n");

            break;

        case 3: ;

            char num_2 [256];
            char titre_2 [256];
            char auteur_2 [256];

            int indicateur_2;
            do{
                indicateur_2=0;

                printf ("Veuillez ecrire le numéro de l’ouvrage à supprimer ou écrivez 'retour' pour revenir à la liste d'actions.\n\n");
                fgets (num_2,sizeof(num_2), stdin);
                if(!strcmp(num_2,"retour\n")){
                    indicateur_2=1;
                    break;
                }
                if(!atoi(num_2) && strcmp(num_2,"0\n")){
                    printf("\nceci n'est pas un numéro!!\nRéessayez!\n");
                    indicateur_2=1;
                }

            }while(indicateur_2);//pour rester dans la boucle tant que la valeur est invalide
            if(indicateur_2){break;}//pour revenir à la list d'action

            printf ("\nVeuillez ecrire le titre de l’ouvrage.\n\n");
            fgets (titre_2,sizeof(titre_2), stdin);
            titre_2[strlen(titre_2)-1] = '\0';

            printf ("\nVeuillez ecrire le nom de l’auteur de l’ouvrage.\n\n");
            fgets (auteur_2,sizeof(auteur_2), stdin);
            auteur_2[strlen(auteur_2)-1] = '\0';

            supprimer_livre(b , atoi(num_2) , titre_2 , auteur_2 );

            break;

        case 4: ;

            char num_3 [256];

            int indicateur_3;
            do{
                indicateur_3=0;

                printf ("Veuillez ecrire le numéro de l’ouvrage à rechercher ou écrivez 'retour' pour revenir à la liste d'actions.\n\n");
                fgets (num_3,sizeof(num_3), stdin);
                if(!strcmp(num_3,"retour\n")){
                    indicateur_3=1;
                    break;
                }
                if(!atoi(num_3) && strcmp(num_2,"0\n")){
                    printf("\nceci n'est pas un numéro!!\nRéessayez!\n");
                    indicateur_3=1;
                }

            }while(indicateur_3);//pour rester dans la boucle tant que la valeur est invalide
            if(indicateur_3){break;}//pour revenir à la list d'action

            Livre *res = recherche_livre_num(b , atoi(num_2));
            if(res){
                afficher_livre(res);
            }

            break;

        case 5: ;

            char titre_3 [256];

            printf ("Veuillez ecrire le titre de l’ouvrage à rechercher ou écrivez 'retour' pour revenir à la liste d'actions.\n\n");
            
            fgets (titre_3,sizeof(titre_3), stdin);
            titre_3[strlen(titre_3)-1] = '\0';

            if(!strcmp(titre_3,"retour")){
                break;
            }
            
            Livre *res_2 = recherche_livre_titre(b , titre_3);
            if(res_2){
                afficher_livre(res_2);
            }

            break;

        case 6: ;

            char auteur_3 [256];

            printf ("Veuillez ecrire le nom de l’auteur qe vous souhaitez rechercher ses livres ou écrivez 'retour' pour revenir à la liste d'actions.\n\n");
            
            fgets (auteur_3,sizeof(auteur_3), stdin);
            auteur_3[strlen(auteur_3)-1] = '\0';

            if(!strcmp(auteur_3,"retour")){
                break;
            }
            
            Biblio *res_3 = recherche_livres_auteur(b , auteur_3);
            if(res_3){
                printf("\nVoilà une mini biblio contenant le(s) livr(e) de l'auteur %s",auteur_3);
                afficher_biblio(res_3);
                break;
            }
            printf("\nAucun livre n'a été trouvé!\n");
            break;

        case 7: ;
            Livre *dup = dupliques(b);

            if(dup){
                printf("voilà le(s) livre(s) dupliqué(s):\n");
            }else{
                printf("il n'y a pas des livres dupliqués!\n");
            }
            while(dup){
                afficher_livre(dup);
                dup = dup->suiv;
            }
            break;

        default:
            printf("veuillez choisir un des numéros aux quelles est associé une action!\n\n");
            break;
        }

    } while(rep !=0);

    printf ("Merci, et au revoir.\n\n");
    return 0;
}