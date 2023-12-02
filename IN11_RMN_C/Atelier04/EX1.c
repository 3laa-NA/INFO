#include <stdio.h>

void gauss_sp(float *a, float *b, int n) {

    for (int i = 0; i < n; i++) {

        // Étape de normalisation pour rendre l'élément diagonal égal à 1
        float pivot = a [i*n +i];  // Élément diagonal
        for (int j = i; j < n; j++) {
            a  [i*n + j] /= pivot;  // Normalisation de la ligne i
        }

        b[i] /= pivot;  // Normalisation du vecteur second membre

        // Étape d'élimination pour rendre les éléments en dehors de la diagonale égaux à 0
        for (int k = 0; k < n; k++) {
            if (k != i) {
                float factor = a [k*n + i];  // Facteur d'élimination
                for (int j = i; j < n; j++) {
                    a [k*n + j] -= factor * (a [i*n + j]);  // Élimination des éléments
                }
                b[k] -= factor * b[i];  // Mise à jour du vecteur second membre
            }
        }
    }
}

int main() {
    float A[16] = {2.5, 1.5, 1.7, 2.5, 1.7, 1.8, 2.2, 1.8, 2.0, 1.2, 2.5, 3.0, 2.1, 1.2, 2.2, 1.5};
    float B[4] = {11.11, 10.67, 12.41, 10.52};
    int n = 4;  // Ordre du système

    // Résoudre le système linéaire
    gauss_sp(A, B, n);

    // Afficher les résultats
    printf("Le coût au kilo de chaque aliment est :\n");
    printf("Carottes : %.2f euros\n", B[0]);
    printf("Navets   : %.2f euros\n", B[1]);
    printf("Tomates  : %.2f euros\n", B[2]);
    printf("Pommes de terre : %.2f euros\n", B[3]);

    return 0;
}
