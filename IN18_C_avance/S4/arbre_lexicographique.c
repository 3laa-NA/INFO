#include "arbre_lexicographique.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

PNoeud creer_noeud(char lettre){
  PNoeud pn=(PNoeud)malloc(sizeof(Noeud));
  if (pn==NULL) {
    printf("Impossible d'allouer un noeud\n");
    return NULL;
  }
 
  pn->lettre=lettre;
  pn->fin_de_mot=non_fin;
  pn->frere_suivant=NULL;
  pn->fils=NULL;
  return pn;
}

void inserer_lettre(PNoeud *racine, PNoeud *n_lettre, char lettre) {
  PNoeud prec=NULL;
  PNoeud n=*racine;
  if (n==NULL) {
    *racine=creer_noeud(lettre);
    *n_lettre=*racine;
    return;
  }

  while(n!=NULL) {
    if (n->lettre == lettre) {
      *n_lettre=n;
      return;
    }
    if (n->lettre>lettre) {
      // on doit inserer avant n
      if (prec==NULL) {
        // insertion en tete
        prec=creer_noeud(lettre);
        prec->frere_suivant=n;
        *racine=prec;
        *n_lettre=*racine;
      }
      else {
        *n_lettre=creer_noeud(lettre);
        prec->frere_suivant=*n_lettre;
        (*n_lettre)->frere_suivant=n;
      }
      return;
    }
    prec=n;
    n = n->frere_suivant;
  }
  *n_lettre=creer_noeud(lettre);
  prec->frere_suivant=*n_lettre;
}

PNoeud ajouter_mot(PNoeud racine, char *mot) {
  PNoeud n=NULL;
  if (strlen(mot)==0) {
    return NULL;
  }
  inserer_lettre(&racine,&n,mot[0]);
  if (strlen(mot)==1) {
    n->fin_de_mot=fin;
  }
  else {
    n->fils=ajouter_mot(n->fils,mot+1);
  }
  return racine;
}

int taille(PNoeud racine) {
  if (racine==NULL) {
    return 0;
  }
  else {
    return 1+taille(racine->frere_suivant);
  }
}

void afficher_mots(PNoeud n, char mot_en_cours[], int index) {

  /* a completer. Exercice 4, question 1 */

  if(!n) return;

  if(index>=LONGUEUR_MAX_MOT) return;

  if(n->frere_suivant){
    afficher_mots(n->frere_suivant,mot_en_cours,index);
  }

  mot_en_cours[index] = n->lettre;

  if(n->fin_de_mot==fin){
    mot_en_cours[index+1]='\0';
    printf("%s\n",mot_en_cours);
  }

  afficher_mots(n->fils,mot_en_cours,index+1);

}

void afficher_dico(PNoeud racine) {

  PNoeud n=racine;

  char mot_en_cours[LONGUEUR_MAX_MOT];

  afficher_mots(n,mot_en_cours,0);

}

void detruire_dico(PNoeud dico) {

  /* a completer. Exercice 4, question 2 */

  if (!dico) return;

  detruire_dico(dico->fils);
  detruire_dico(dico->frere_suivant);
  free(dico);

}

PNoeud chercher_lettre(PNoeud n, char lettre) {
  if (n==NULL) {
    return NULL;
  }
  if (n->lettre==lettre) {
    return n;
  }
  if (n->lettre>lettre) {
    return NULL;
  }
  return chercher_lettre(n->frere_suivant,lettre);
}

int rechercher_mot(PNoeud dico, char *mot) {
  PNoeud n=chercher_lettre(dico,mot[0]);
  if (n==NULL) {
    return 0;
  }
  if (strlen(mot)==1) {
    return n->fin_de_mot == fin;
  }
  return rechercher_mot(n->fils,mot+1);
}

PNoeud lire_dico(const char *nom_fichier) {

  /* a completer. Exercice 4, question 3 */

  char ligne[LONGUEUR_MAX_MOT];
  PNoeud dico = NULL;

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
