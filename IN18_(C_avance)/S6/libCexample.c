#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <search.h>


int comparer_int(const void *v1, const void *v2) {
  const int *iv1=(const int *)v1;
  const int *iv2=(const int *)v2;
  return (*iv1>*iv2)-(*iv1<*iv2);
}

void print_node(const void *current_node, VISIT v, int level) {
  if ((v==postorder)||(v==leaf)) {
    int **v=(int **)current_node;
    printf("%d ",**v);
  }
}

int main(void) {

  size_t nb_max=10;
  int v_max=2*nb_max;
  int i;
  int *tab=(int*)malloc(sizeof(int)*nb_max);
  size_t nb=0;
  int nb_search=10000;

  clock_t start, end;
  double cpu_time_used;

  srand(time(NULL));

  // initialisation du tableau
  start=clock();
  while (nb<nb_max) {
    int nv=rand()%v_max;
    lsearch(&nv,tab,&nb, sizeof(int), comparer_int);
  }
  end=clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Tableau cree en %lf s\n", cpu_time_used);
  // affichage
  /*printf("Apres creation:\n");
  for (i=0;i<nb_max; i++) {
    printf("tab[%d]=%d\n",i,tab[i]);
    }*/

  // recherche de points
  start=clock();
  int nb_trouve=0;
  for (i=0;i<nb_search;i++) {
    int ns=rand()%v_max;
    if(lfind(&ns,tab,&nb_max,sizeof(int), comparer_int)!=NULL) {
      nb_trouve++;
    }
  }
  end=clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Recherche en %lf s. %d valeurs tirees ont ete trouvees dans le tableau (sur %d).\n",cpu_time_used,nb_trouve,nb_search);

  // tri du tableau
  start=clock();
  qsort(tab, nb_max, sizeof(int), comparer_int);
  end=clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Tableau trie en %lf s\n", cpu_time_used);

  // affichage
  /*printf("Apres tri:\n");
  for (i=0;i<nb_max; i++) {
    printf("tab[%d]=%d\n",i,tab[i]);
    }*/

  // recherche de points
  start=clock();
  nb_trouve=0;
  for (i=0;i<nb_search;i++) {
    int ns=rand()%v_max;
    if(bsearch(&ns,tab,nb_max,sizeof(int), comparer_int)!=NULL) {
      nb_trouve++;
    }
  }
  end=clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Recherche en %lf s. %d valeurs tirees ont ete trouvees dans le tableau (sur %d).\n",cpu_time_used,nb_trouve,nb_search);


  void *root=NULL;
  // creation de l'arbre
  start=clock();
  nb=0;
  while (nb<nb_max) {
    int *nv=(int *)malloc(sizeof(int));
    *nv=rand()%v_max;
    int **res=tsearch(nv,&root, comparer_int);
    if (*res!=nv) {
      // la valeur était déjà dans l'arbre...
      free(nv);
    }
    else {
      nb++;
    }
  }
  end=clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Arbre cree en %lf.\n", cpu_time_used);
  // affichage
  printf("Arbre:\n");
  twalk(root, print_node);
  printf("\n");

  // recherche de points
  start=clock();
  nb_trouve=0;
  for (i=0;i<nb_search;i++) {
    int ns=rand()%v_max;
    if(tfind(&ns,&root, comparer_int)!=NULL) {
      nb_trouve++;
    }
  }
  end=clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Recherche en %lf s. %d valeurs tirees ont ete trouvees dans le tableau (sur %d).\n",cpu_time_used,nb_trouve,nb_search);
  
  //tdestroy(root,free);
  while(root!=NULL) {
    int **v=(int **)root;
    int *pv=*v; // il faut bien recuperer la donnee, 
    // on ne pourra plus y acceder via *v une fois le noeud detruit.
  
    tdelete((void *)pv,&root,comparer_int);
    free(pv);
  }

  free(tab);

  return 0;
}

