#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h> 


int compte_mots_chaine(char *chaine) {
    int compteur = 0; // compteur de mots
    bool est_un_mot = false;

    for (int i = 0; chaine[i] != '\0'; i++) { 
        if (chaine[i] == ' ' || chaine[i] == '\n') { // Si le caractère est un espace ou un saut de ligne -> on est arriver a la fin d'un mot
            est_un_mot = false; 
        } 
        else {
            if (!est_un_mot) { // Si le caractère actuel n'était pas déjà dans un mot -> nouveau mot -> Incrémente le compteur de mots
                compteur++; 
                est_un_mot = true;
            }
        }
    }

    return compteur; 
}

char **decompose_chaine(char *chaine)
{
    /* Fonction vue en TD, exercice 2, question 7 */
    char *pc= chaine;
    int nb_mots=0;
    char **ptab;
    char *psrc_mot;
    int ind_mot=0;

    //comptages des mots
    nb_mots=compte_mots_chaine(chaine);

    if (nb_mots == 0)
    return NULL;
    // allocation du tableau

    ptab = malloc((nb_mots + 1) * sizeof(char *));
    ptab[nb_mots] = NULL;

    // copie des mots

    pc=chaine;
    while (*pc)
    {
        if(*pc == ' ')
        {
            pc++;
            continue;
        }

        psrc_mot = pc;

        while((*pc != ' ') && (*pc)) pc++;

        //allocation du mot
        ptab[ind_mot] = malloc((pc - psrc_mot + 1)* sizeof(char));
        //copie du mot
        memcpy(ptab[ind_mot], psrc_mot, pc - psrc_mot);
        //insertion du marqueur de fin de chaine
        *(ptab[ind_mot] + (pc - psrc_mot)) = '\0';

        ind_mot++;
    }
    return ptab;
}

char *compose_chaine(char **ptab_mots) {
    int n = 0; 

    // Calcule la longueur totale 
    for (int i = 0; ptab_mots[i] != NULL; i++) {
        for (int j = 0; ptab_mots[i][j] != '\0'; j++) {
            n++;
        }
        n++; // compter un espace entre les mots
    }

    char *res = malloc(sizeof(char) * (n + 1)); // Alloue de la mémoire pour la nouvelle chaîne (+1 pour le caractère nul de fin)

    int ind = 0;
    for (int i = 0; ptab_mots[i] != NULL; i++) {
        for (int j = 0; ptab_mots[i][j] != '\0'; j++) {
            res[ind] = ptab_mots[i][j]; // Copie chaque caractère du mot dans la nouvelle chaîne
            ind++;
        }
        res[ind] = ' '; // Ajoute un espace entre les mots
        ind++;
    }

    res[n] = '\0'; // Termine la nouvelle chaîne avec un caractère nul de fin

    return res; 

}

void detruit_tab_mots(char **ptab_mots)
{

  /* Fonction vue en TD, exercice 2, question 5 */

  int i=0;

  if (ptab_mots){
    while(ptab_mots[i]!= NULL){
      free(ptab_mots[i++]);
      i++;
    }

    free(ptab_mots);
  }
}



int compte_mots(char *tableau[]) {
    int mots = 0; // le compteur de mots à zéro

    for (int i = 0; tableau[i] != NULL; i++) { 
        mots++; 
    }

    return mots; 
}

void affiche_tab_mots(char *tableau[]) {
    for (int i = 0; tableau[i] != NULL; i++) { 
        printf("%s ", tableau[i]); 
    }

    printf("\n"); 
}


char **reduit_tab_mots(char **ptab_mots){

    for (int i = 0; ptab_mots[i] != NULL; i++) {
        for (int j = i+1; ptab_mots[j] != NULL; j++) {
            int k =0;
            while ( ptab_mots[i][k] == ptab_mots[j][k] & ptab_mots[j][k] != '\0' ){
                k++;
            }
            if(ptab_mots[i][k] == ptab_mots[j][k] & ptab_mots[j][k] == '\0' ){
                ptab_mots[j]=ptab_mots[i];
            }
        }
    }

    return ptab_mots;
}

/*
EX 4 : 
q2 : Oui, on simplement modifier la fonction detruit_tab_mots pour qu'elle s'arrête quand on arrive à la fin du tableau (on arrive à NULL).
*/

int main() {

    char *ch = "Je me nomme Alaa et je broie la langue de Moliere";
    printf("Nombre de mots dans la chaine : %s\nEst %d\n", ch, compte_mots_chaine(ch));

    char *tableauMots[] = {"mot1", "et", "mot2", "et", "mot3", NULL};
    int motsDansTableau = compte_mots(tableauMots);

    printf("Mots dans le tableau : %d\n", motsDansTableau);

    printf("les mots dans le tableau sont : \n");
    affiche_tab_mots(tableauMots);

    char *chaineComposee = compose_chaine(tableauMots);
    printf("chaine composée : %s\n", chaineComposee);

    free(chaineComposee); // Libère la mémoire allouée pour la chaîne composée

    char **tab_reduite =reduit_tab_mots(tableauMots);

    char *chaineReduite = compose_chaine(tab_reduite);
    printf("chaine composée du tableau réduite : %s\n", chaineReduite);

    free(chaineComposee);
    
    return 0;
}
