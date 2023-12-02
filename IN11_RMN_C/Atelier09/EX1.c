#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Évalue le polynôme en utilisant la méthode de Horner classique
void eval_Horner_1(double a, double* coeff_f, int n, double* f_a) {
    *f_a = coeff_f[n];
    for (int i = n - 1; i >= 0; i--) {
        *f_a = *f_a * a + coeff_f[i];
    }
}

void multipointeval_Horner_1(double* a, double* coeff_f, int n, double* f_a){

    for(int i=0; i<n; i++){
        eval_Horner_1(a[i], coeff_f, n, &f_a[i*2]); // Évaluation en a[i]
        eval_Horner_1(-a[i], coeff_f, n, &f_a[i*2 + 1]); // Évaluation en -a[i]
    }
    
}

// Évalue le polynôme en utilisant une variante de la méthode de Horner
void eval_Horner_2(double a, double* coeff_f, int n, double* f_a, double* f_minus_a){
    double yi, yp, x2;
    int i;

    x2 = a * a;

    // Initialisation des variables en fonction de la parité de n
    if (n % 2) {
        yi = coeff_f[n];
        yp = coeff_f[n-1];
        i = n - 2; 
    } else { 
        yi = 0;
        yp = coeff_f[n];
        i = n - 1; 
    }

    // Boucle pour évaluer le polynôme de manière efficace
    for (; i >= 0; i -= 2) {
        yi = yi * x2 + coeff_f[i];
        if (i > 0) {
            yp = yp * x2 + coeff_f[i - 1];
        }   
    }

    // Calcul final du résultat et de son opposé
    *f_a = yp + a * yi;
    *f_minus_a = yp - a * yi;
}

void multipointeval_Horner_2(double* a, double* coeff_f, int n, double* f_a){

    for(int i=0; i<n; i++){
        eval_Horner_2(a[i], coeff_f, n, &f_a[i*2], &f_a[i*2 + 1]);
    }
    
}

int main(){

    double* f_a = malloc(sizeof(double));
    double* f_minus_a = malloc(sizeof(double));

    clock_t debut, fin;
    double t_fun_1 = 0, t_fun_2 = 0;

    int n = 1;

    for(int i = 0; i < 17; i++) {
        if(i > 0) {
            n *= 2;
        }

        // Générer des coefficients aléatoires pour le polynôme
        double* coef = malloc((n + 1) * sizeof(double));

        for(int j = 0; j <= n; j++) {
            coef[j] = rand() / (double)RAND_MAX * 2 - 1;
        }

        // Mesurer le temps pris par eval_Horner_1
        debut = clock();
        eval_Horner_1(3.0, coef, n, f_a);
        fin = clock();
        t_fun_1 += ((double) (fin - debut)) / CLOCKS_PER_SEC;

        // Mesurer le temps pris par eval_Horner_2
        debut = clock();
        eval_Horner_2(3.0, coef, n, f_a, f_minus_a);
        fin = clock();
        t_fun_2 += ((double) (fin - debut)) / CLOCKS_PER_SEC;    

        // Libérer la mémoire allouée pour les coefficients
        free(coef);   
    }

    // Afficher les temps d'exécution
    printf("temps pris par eval_Horner_1 : %f secondes\n" , t_fun_1);
    printf("temps pris par eval_Horner_2 : %f secondes\n" , t_fun_2);

    // Libérer la mémoire allouée pour les résultats
    free(f_a);
    free(f_minus_a);

    return 0;
}
