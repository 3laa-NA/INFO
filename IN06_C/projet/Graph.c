#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Graph.h"
#include "Struct_Liste.h"
#include "file.h"

Sommet *RechercheCreeSommet(Graphe *G, double x, double y){

    Sommet *s = NULL;
    for(int i=0; i<G->nbsom; i++){ // Parcours des sommets existants dans le graphe
        if(G->T_som[i]->x == x && G->T_som[i]->y == y){
            s = G->T_som[i];
            break;
        }
    }

    if(!s){ // Si le sommet n'existe pas encore, on le crée
        s = (Sommet*)malloc(sizeof(Sommet));
        s->num = G->nbsom++;
        s->x = x;
        s->y = y;
        s->L_voisin = NULL;
        G->T_som[s->num] = s;
    }

    return s;
}

Arete *RechercheCreeArete(Sommet *s1, Sommet *s2){
    Cellule_arete *tmp = s1->L_voisin;

    while(tmp){ // Parcours des arêtes voisines du sommet s1
        if (tmp->a->u == s2->num || tmp->a->v == s2->num){
            return tmp->a;
        } 
        tmp = tmp->suiv;
    }

    // Création de la nouvelle arête
    Arete *a = (Arete*)malloc(sizeof(Arete));
    a->u = s1->num;
    a->v = s2->num;

    // Ajout de l'arête à la liste des voisins de s1 et de s2
    Cellule_arete *ca1 = (Cellule_arete*)malloc(sizeof(Cellule_arete));
    ca1->a = a;
    ca1->suiv = s1->L_voisin;
    s1->L_voisin = ca1;

    Cellule_arete *ca2 = (Cellule_arete*)malloc(sizeof(Cellule_arete));
    ca2->a = a;
    ca2->suiv = s2->L_voisin;
    s2->L_voisin = ca2;

    return a;
}

Graphe* creerGraphe(Reseau* R){
    
    Graphe *G = (Graphe*)malloc(sizeof(Graphe));
    G->gamma = R->gamma;
    G->nbsom = 0;
    G->T_commod = NULL;
    G->T_som = NULL;

    CellNoeud *cn = R->noeuds;

    while(cn){ // Parcours des nœuds du réseau pour créer les sommets du graphe
        Noeud *n = cn->nd;
        Sommet *s = RechercheCreeSommet(G, n->x, n->y);

        CellNoeud *cn_v = n->voisins;
        while(cn_v){ // Parcours des voisins de chaque nœud pour créer les arêtes du graphe

            if(cn_v->nd->num < n->num){
                Sommet* s_v = RechercheCreeSommet(G, cn_v->nd->x, cn_v->nd->y);
                RechercheCreeArete(s, s_v);
            }
            cn_v = cn_v->suiv;
        }

        cn = cn->suiv;
    }

    CellCommodite *R_cmd = R->commodites;
    int i = -1;

    while(R_cmd){ // Parcours des commodités du réseau

        Commod *cmd = (Commod*)malloc(sizeof(Commod));

        //Recherche des numéros des sommets correspondants aux commodités
        cmd->e1 = RechercheCreeSommet(R, R_cmd->extrA->x, R_cmd->extrA->y)->num;
        cmd->e1 = RechercheCreeSommet(R, R_cmd->extrB->x, R_cmd->extrB->y)->num;

        G->T_commod[i++] = *cmd;

        R_cmd = R_cmd->suiv;
    }

    G->nbcommod = i++;


    return G;

}

//fonction recursive
void TaillesChemins(IntFile *f, Graphe *G, Sommet *s, int destination, int n){

    //conditions de sortie
    if(!s || n > G->nbsom) return;

    if(s->num == destination){
        enfiler(f, n);
    }

    Cellule_arete *tmp = s->L_voisin;

    while(tmp){ // Parcours des voisins du sommet
        if(tmp->a->u == s->num){
            TaillesChemins(f, G, G->T_som[tmp->a->v], destination, n+1);
        }else{
            TaillesChemins(f, G, G->T_som[tmp->a->u], destination, n+1);
        }

        tmp = tmp->suiv;
    }
}

int plusPetitNbAretes(Graphe *G, int u, int v) {
    IntFile *file = creer_file();

    Sommet *s_dep = G->T_som[u]; //sommet de depart

    // Calcul des tailles des chemins entre u et v
    TaillesChemins(file, G, s_dep, v, 0);

    int minVal = defiler(file); //egale à -1 si vide

    while (!est_vide(file)){ // Recherche du plus petit nombre d'arêtes
        int val = defiler(file);
        if (val < minVal) {
            minVal = val;
        }
    }

    return minVal;

}

