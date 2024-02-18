#ifndef _BIBILIO_H_H_
#define _BIBILIO_H_H_

typedef struct livreh{
    int clef;
    int num;
    char *titre;
    char *auteur;
    struct livreh * suivant;
} LivreH;

typedef struct table {
    int nE; /*nombre d’elements contenus dans la table de hachage */
    int m; /*taille de la table de hachage */
    LivreH ** T; /*table de hachage avec resolution des collisions par chainage */
} BiblioH;

int fonctionClef(char* auteur);

LivreH* creer_livre(int num,char* titre,char* auteur);

void liberer_livre(LivreH* l);

BiblioH* creer_biblio(int m);

void liberer_biblio(BiblioH* b);

int fonctionHachage(int cle, int m);

void inserer(BiblioH* b,int num,char* titre,char* auteur);

#endif