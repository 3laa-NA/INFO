#include <stdio.h>

void interpol_Lagrange(double* a, double* f_a, int n, double* coeff_f) {
    // La fonction interpol_Lagrange calcule les coefficients du polynôme interpolateur de Lagrange

    for (int i = 0; i < n; i++) {
        coeff_f[i] = 0.0; // Initialiser le coefficient à 0

        // Calcul du terme du polynôme pour le point i
        for (int j = 0; j < n; j++) {
            if (j != i) {
                double term = 1.0;

                // Calcul du terme de Lagrange pour le point i et le point j
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j) {
                        term *= (a[i] - a[k]) / (a[i] - a[j]);
                    }
                }

                // Ajouter le terme au coefficient du polynôme
                coeff_f[i] += term * f_a[j];
            }
        }
    }
}

int main() {
    // Exemple d'utilisation de la fonction interpol_Lagrange

    double a[] = {1.0, 2.0, 3.0}; // Les points d'interpolation
    double f_a[] = {4.0, 5.0, 6.0}; // Les valeurs correspondantes
    int n = 3; // Nombre de points

    double coeff_f[n]; // Coefficients du polynôme interpolateur

    interpol_Lagrange(a, f_a, n, coeff_f);

    // Afficher les coefficients du polynôme interpolateur
    printf("Coefficients du polynôme interpolateur de Lagrange :\n");
    for (int i = 0; i < n; i++) {
        printf("a%d = %.2f\n", i, coeff_f[i]);
    }

    return 0;
}
