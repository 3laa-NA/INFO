#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "arbre_lexicographique_tab.h"


PNoeudTab creer_noeud(char lettre) {
  /* a completer. Exercice 6, question 1 */

  PNoeudTab pn=(PNoeudTab)malloc(sizeof(NoeudTab));
  if (pn==NULL) {
    printf("Impossible d'allouer un noeud\n");
    return NULL;
  }

  for(int i=0;i<26;i++){
    pn->fils[i] = NULL;
  }
 
  pn->lettre=lettre;
  pn->fin_de_mot=non_fin;

  return pn;

}

PNoeudTab ajouter_mot(PNoeudTab racine, char *mot) {
  /* a completer. Exercice 6, question 1 */

  if (strlen(mot)==0) {
    return NULL;
  }
  
  int i = (int)*mot - 97;

  if (!racine->fils[i]) {
    racine->fils[i] = creer_noeud(*mot);
  }

  if (strlen(mot)==1) {
    racine->fils[i]->fin_de_mot=fin;
  }else{
    racine->fils[i] = ajouter_mot(racine->fils[i],mot+1);
  }

  return racine;

}

void afficher_mots(PNoeudTab n, char mot_en_cours[LONGUEUR_MAX_MOT], int index) {
  /* a completer. Exercice 6, question 1 */

  if(!n) return;

  if(index>=LONGUEUR_MAX_MOT) return;

  mot_en_cours[index] = n->lettre;
  
  if(n->fin_de_mot==fin){
    mot_en_cours[index+1]='\0';
    printf("%s\n",mot_en_cours);
  }
  
  for(int i = 0; i < 26;i++){
    if(n->fils[i]){
      afficher_mots(n->fils[i],mot_en_cours,index+1);
    }
  }

}

void afficher_dico(PNoeudTab racine) {
  /* a completer. Exercice 6, question 1 */

  PNoeudTab n=racine;

  char mot_en_cours[LONGUEUR_MAX_MOT];

  for(int i = 0; i < 26;i++){
    if(n->fils[i]){
      afficher_mots(n->fils[i],mot_en_cours,0);
    }
  }

}

void detruire_dico(PNoeudTab dico) {
  /* a completer. Exercice 6, question 1 */

  if (!dico) return;

  for(int i = 0; i < 26;i++){
    detruire_dico(dico->fils[i]);
  }

  free(dico);

}

int rechercher_mot(PNoeudTab dico, char *mot) {
  /* a completer. Exercice 6, question 1 */
  
  if (dico==NULL) {
    return 0;
  }
  
  if (strlen(mot)==1) {
    return dico->fin_de_mot == fin;
  }
  
  int i = (int)*mot - 97;
  
  if(!dico->fils[i]){
    return 0;
  }

  return rechercher_mot(dico->fils[i],mot+1);

}

PNoeudTab lire_dico(const char *nom_fichier) {
  /* a completer. Exercice 6, question 2 */

  char ligne[LONGUEUR_MAX_MOT];
  PNoeudTab dico = creer_noeud('.');

  FILE *f=fopen(nom_fichier,"r");

  if (f==NULL){
    printf("Erreur lors de l'ouverture du fichier %s\n",nom_fichier);
    return NULL;
  }

  while(fgets(ligne,LONGUEUR_MAX_MOT,f)){
    ligne[strlen(ligne)-1]='\0';
    dico=ajouter_mot(dico,ligne);
  }
  
  fclose(f);
  return dico;

}


