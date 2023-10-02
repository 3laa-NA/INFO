#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void prodmatmat(double *a, double *b, double *p, int n) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            *(p + i * n + j) = 0;
            for (k = 0; k < n; k++) {
                *(p + i * n + j) += *(a + i * n + k) * *(b + k * n + j);
            }
        }
    }
}

void prodmatmat_op(double *a, double *b, double *p, int n) {
    double *pa, *pb, *pp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pp = p + i * n + j;
            *pp = 0;
            pa = a + i * n;
            pb = b + j;
            for (int k = 0; k < n; k++) {
                *pp += (*pa) * (*pb);
                pa++;
                pb += n;
            }
        }
    }
}

void remplirMatriceAleatoirement(double *matrice, int n) {
    for (int i = 0; i < n * n; i++) {
        matrice[i] = ((double)rand() / RAND_MAX) * 2.0 - 1.0; // Valeurs aléatoires entre -1 et 1
    }
}


int main() {
    int n;
    printf("Entrez la dimension de la matrice (n) : ");
    scanf("%d", &n);

    double *a = malloc(sizeof(double) * n * n);
    double *b = malloc(sizeof(double) * n * n);
    double *p = malloc(sizeof(double) * n * n);

    if (a == NULL || b == NULL || p == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        return 1;
    }

    srand(time(NULL)); // Initialiser le générateur de nombres aléatoires avec une graine différente

    remplirMatriceAleatoirement(a, n);
    remplirMatriceAleatoirement(b, n);

    clock_t debut_classique = clock();
    prodmatmat(a, b, p, n);
    clock_t fin_classique = clock();

    double temps_classique = (double)(fin_classique - debut_classique) / CLOCKS_PER_SEC;

    printf("Temps de calcul pour la fonction classique : %.6f secondes\n", temps_classique);



    clock_t debut_op = clock();
    prodmatmat_op(a, b, p, n);
    clock_t fin_op = clock();

    double temps_op = (double)(fin_op - debut_op) / CLOCKS_PER_SEC;

    printf("Temps de calcul pour la fonction optimisée : %.6f secondes\n", temps_classique);


    free(a);
    free(b);
    free(p);

    return 0;
}
