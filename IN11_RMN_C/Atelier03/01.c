#include <stdio.h>


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

void afficherMatrice(double *matrice, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.1lf\t", *(matrice + i * n + j));
        }
        printf("\n");
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


int main() {
    double creatures[4][4] = {
        {15, 34, 27, 2},
        {8, 23, 10, 1},
        {11, 17, 9, 4},
        {8, 65, 45, 7}
    };

    double ratios[4][4] = {
        {1, 2, 2.5, 2},
        {0.7, 1, 1.5, 1},
        {0.6, 1.1, 1.2, 0.8},
        {10, 15, 7, 5}
    };

    double result[4][4];

    prodmatmat(&creatures[0][0], &ratios[0][0], &result[0][0], 4);

    printf("Quantités d'aliments nécessaires pour chaque armée :\n");
    afficherMatrice(&result[0][0], 4);

    return 0;
}
