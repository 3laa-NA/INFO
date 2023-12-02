#include <stdio.h>
#include <math.h>

// Fonction qui implemente l'algorithme de Horner pour evaluer un polynome
double horner(double *p, int n, double val) {
    double result = p[n]; // Initialisation du resultat avec le coefficient de plus haut degre
    for (int i = n - 1; i >= 0; i--) {
        result = result * val + p[i]; // Mise a jour du resultat en suivant le schema de Horner
    }
    return result; // Retourne le resultat final
}

// Fonction qui calcule la suite recurrente en utilisant l'algorithme de Horner
double suite_recurrence(double x, double alpha) {
    // Coefficients du polynome pour la suite recurrente
    double p[] = {4, -4 * alpha + 3, -alpha, -2 * alpha, 0, 0, 0, 0};
    return horner(p, 7, x); // Appelle la fonction Horner pour evaluer le polynome a la valeur specifiee
}

// Fonction qui calcule la derivee numerique de la suite recurrente par rapport a x
double derivee(double x, double alpha) {
    double h = 1e-6; // Petit pas
    return (suite_recurrence(x + h, alpha) - suite_recurrence(x, alpha)) / h; // Calcul de la derivee numerique
}

// Fonction qui etudie la convergence de la suite
void convergence(double x0, double alpha, double epsilon) {
    double xn = x0; // Initialisation de la valeur xn avec x0
    double xs = 0; // Initialisation de la valeur limite
    int n = 0; // Initialisation du compteur
    double prev_diff = fabs(xn - xs); // Initialisation de la difference precedente
    double curr_diff; // Initialisation de la difference actuelle
    double variation_relative = 1; // Initialisation de la variation relative

    double a = xs; // Point fixe
    double f_prime_a = derivee(a, alpha); // Calcul de la derivee de la suite recurrente en a

    do {
        xs = xn; // Mise a jour de la valeur limite avec la valeur precedente
        xn = suite_recurrence(xn, alpha); // Calcul de la valeur suivante de la suite
        n++; // Increment du compteur
        curr_diff = fabs(xn - xs); // Calcul de la difference actuelle

        double variation = round((curr_diff / prev_diff) * 10000) / 10000; // Calcul de la variation relative

        prev_diff = curr_diff; // Mise a jour de la difference precedente
        variation_relative = variation; // Mise a jour de la variation relative
    } while (curr_diff >= epsilon); // Verification de la condition de convergence

    if (f_prime_a != 0) {
        if (fabs(f_prime_a) < 1) {
            printf("Convergence lineaire, p = %.2f\n", fabs(f_prime_a)); // Affichage du type de convergence lineaire
        } else {
            printf("Convergence exponentielle, p = %.2f\n", 1.0 / fabs(f_prime_a)); // Affichage du type de convergence exponentielle
        }
    } else {
        printf("Convergence exponentielle, p = %.2f\n", variation_relative); // Affichage du type de convergence exponentielle
    }
}

int main() {
    double alpha, x0, epsilon;

    // Demander les valeurs de x0, alpha et epsilon a l'utilisateur
    printf("Entrez la valeur de x0 : ");
    scanf("%lf", &x0);
    printf("Entrez la valeur de alpha : ");
    scanf("%lf", &alpha);
    printf("Entrez la valeur de epsilon : ");
    scanf("%lf", &epsilon);

    // Appeler la fonction de convergence pour les valeurs specifiees
    convergence(x0, alpha, epsilon);

    return 0;
}
