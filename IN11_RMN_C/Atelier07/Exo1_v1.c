#include <stdio.h>
#include <math.h>
#include <time.h>

#define N 100000
#define RAND_MAX 115


// Fonction pour obtenir la valeur absolue d'un nombre
double valeur_absolue(double x){
    if(x < 0){
        return -x; // Retourne la valeur négative de x si x est négatif
    }
    return x; // Retourne x si x est positif ou nul
}

// Fonction pour calculer le nombre de chiffres significatifs communs entre x et y
double bitcommun(double x, double y) {
    double erreur_absolue = valeur_absolue(x - y); // Calcul de l'erreur absolue entre x et y
    double denominateur = valeur_absolue(x + y); // Calcul du denominateur pour Cxy
    double Cxy = 2 * erreur_absolue / denominateur; // Calcul de Cxy selon la formule donnée
    return -log(Cxy) / log(10); // Calcul du logarithme en base 10 de Cxy pour obtenir le nombre de chiffres significatifs communs
}


int bitcommun_opt(double x, double y) {
    // Conversion des valeurs x et y en bits
    long long intX = *(long long*)&x;
    long long intY = *(long long*)&y;
    
    // Calcul de la différence en valeurs entières
    long long diff = intX - intY;
    
    // Si la différence est négative, la convertir en positive
    if (diff < 0) {
        diff = -diff;
    }

    // Calcul du nombre de chiffres significatifs communs en utilisant le bit de poids le plus élevé
    int msb = 63; // Représente le bit de poids le plus élevé

    while (msb >= 0) {
        if ((diff >> msb) & 1) {
            break; // Le bit de poids le plus élevé a été trouvé
        }
        msb--;
    }

    // Calcul du nombre de chiffres significatifs communs
    return msb + 1;
}




int main() {
    

    double x[N], y[N],un=1;
    for(int i=0; i< N; i++){
        x[i] = (un*rand()*10000)/RAND_MAX;
        y[i] = x[i] + (un*rand()*0.0001)/RAND_MAX;
    }

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    for (int i = 0; i < N; i++) {
        int common_bits = bitcommun(x[i], y[i]);
    }
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Temps pour bitcommun     : %f secondes\n", cpu_time_used);

    start = clock();
    for (int i = 0; i < N; i++) {
        int common_bits = bitcommun_opt(x[i], y[i]);
    }
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Temps pour bitcommun_opt : %f secondes\n\n", cpu_time_used);

    // Déclaration des tableaux x et y pour tester avec les valeurs de la video
    double z[] = {1.41421356, 9.87452334, 10.07452334, -2.69998756};
    double t[] = {1.41427845, 9.87901342, 10.07901342, -2.70001234};
    
    // Boucle pour calculer et afficher le nombre de chiffres significatifs communs pour chaque paire de valeurs x et y
    for (int i = 0; i < 4; i++) {
        printf("bit_commun     : Nombre de chiffres significatifs communs entre x et y          : %.2f\n", bitcommun(z[i], t[i]));
        printf("bit_commum_opt : Nombre de chiffres significatifs communs_optimise entre x et y : %d\n\n", bitcommun_opt(z[i], t[i]));

    }

    return 0;
}
