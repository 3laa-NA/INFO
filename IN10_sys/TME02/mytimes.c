#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/times.h>
#include <time.h>


void lance_commande(char *commande){
    struct timeval tv;
    struct timeval tv2;

    gettimeofday(&tv, NULL);

    if(system(commande)){
        printf("la commande '%s' n’a pu être exécutée correctement.\n", commande);
        return;
    }
    
    gettimeofday(&tv2, NULL);

    double t2 = (tv2.tv_sec)*pow(10,6) + (tv2.tv_usec);
    double t1 = (tv.tv_sec)*pow(10,6) + (tv.tv_usec);

    printf("le temps mis par l'exécution de la commande '%s' : %f s\n", commande, (t2-t1)/1e6);

}

void new_lance_commande(char *commande){
    struct tms t1, t2;
    clock_t debut, fin;


    debut = times(&t1);

    if(system(commande)){
        printf("la commande '%s' n’a pu être exécutée correctement.\n", commande);
        return;
    }
    
    fin = times(&t2);

    unsigned long ms = (fin -  debut) * 1000 / CLOCKS_PER_SEC;

    printf("le temps mis par l'exécution de la commande '%s' : %ld ms\n", commande, ms);

}

int main(int argc, char *argv[]) {

    if(argc == 1){
        printf("Il manque les arguments!\n");
        return 1;
    }

    for (int i=1; i<argc; i++){
        //lance_commande(argv[i]);
        new_lance_commande(argv[i]);
    }
    
    return 0;
}




