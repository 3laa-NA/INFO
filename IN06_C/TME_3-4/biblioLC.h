#ifndef _BIBILIO_LC_H_
#define _BIBILIO_LC_H_

typedef struct livre {
 int num ;
 char *titre ;
 char *auteur ;
 struct livre *suiv ;
} Livre ;

typedef struct { /* Tete fictive */
 Livre * L ; /* Premier element */
} Biblio ;


Livre* creer_livre(int num,char* titre,char* auteur);

void liberer_livre(Livre* l);

Biblio* creer_biblio();

void liberer_biblio(Biblio* b);

void inserer_en_tete(Biblio* b,int num,char* titre,char* auteur);

void afficher_livre(Livre* l);

void afficher_biblio(Biblio *b);

Livre *recherche_livre_num(Biblio *b,int n);

Livre *recherche_livre_titre(Biblio *b,char *titre);

Biblio *recherche_livres_auteur(Biblio *b,char *auteur);

void supprimer_livre(Biblio* b,int num,char* titre,char* auteur);

void fusion(Biblio *b1, Biblio *b2);

Livre *dupliques(Biblio *b);

#endif