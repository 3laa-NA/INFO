#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mulpol (double* coeff_f, int n, double* coeff_g, int p, double* coeff_h, int* q){

    for(int i=0; i<= n; i++){

        if(coeff_f[i]!=0){

            for(int j=0; j<= p; j++){
                if(coeff_g[j]!=0){
                    coeff_h[i+j] += coeff_f[i] * coeff_g[j]; // Stockage du terme dans le résultat
                }

            } 

        }

    }
    
    *q = n+p; //rang de h = (rang de f) + (ranf de g)

}

int main() {
    // Définir les polynômes f(x) = 2x^2 + 3x + 1 et g(x) = x + 2
    double coeff_f[] = {1, 3, 2};  // coefficients de f(x)
    int n = 2;  // degré de f(x)
    double coeff_g[] = {1, 2};  // coefficients de g(x)
    int p = 1;  // degré de g(x)

    // Calculer le degré du polynôme résultant h(x)
    int q = n + p;

    // Allouer de la mémoire pour le polynôme résultant h(x)
    double* coeff_h = malloc((q + 1) * sizeof(double));

    // Appeler la fonction mulpol pour multiplier f(x) et g(x)
    mulpol(coeff_f, n, coeff_g, p, coeff_h, &q);

    // Afficher le polynôme résultant h(x)
    printf("Polynôme résultant h(x) : ");
    for (int i = q; i >= 0; i--) {
        if (coeff_h[i] != 0) {
        printf("%.2f*x^%d", coeff_h[i], i);
        if (i > 0) {
            printf(" + ");
        }
    }
    }
    printf("\n");

    // Libérer la mémoire allouée pour le polynôme résultant
    free(coeff_h);

    return 0;
}

