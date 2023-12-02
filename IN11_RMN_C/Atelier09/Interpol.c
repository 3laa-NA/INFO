#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gauss(double* a, double* b, int n) {
  int i, j, k, il;
  double aux, aux2;
  for (i = 0; i < n - 1; i++) {
    aux = *(a + i * n + i);
    for (k = i + 1; k < n; k++) *(a + i * n + k) /= aux;
    *(b + i) /= aux;
    for (k = i + 1; k < n; k++) {
      aux2 = *(a + k * n + i);
      for (j = i + 1; j < n; j++) *(a + k * n + j) -= aux2 * *(a + i * n + j);
      *(b + k) -= aux2 * *(b + i);
    }
  }
  *(b + n - 1) /= *(a + n * n - 1);
  for (i = n - 2; i >= 0; i--) {
    aux = *(b + i);
    for (k = i + 1; k < n; k++) aux -= *(a + i * n + k) * *(b + k);
    *(b + i) = aux;
  }
}

void interpol_linalg(double* a, double* f_a, int n, double* coeff_f) {
  double c[n * n];
  for (int i = 0; i < n; i++) {
    *(c + i * n) = 1;
    coeff_f[i] = f_a[i];
    for (int j = 1; j < n; j++) {
      *(c + i * n + j) = *(c + i * n + j - 1) * a[i];
    }
  }
  gauss(c, coeff_f, n);
}

double sum(double* t, int index_fin, int num) {
  double r = 0;
  for (int i = 0; i < num; i++) {
    r += t[index_fin - i];
  }
  return r;
}

void interpol_Lagrange(double* a, double* f_a, int n, double* coeff_f) {
  double l[n][n];
  double c;
  double d[n];
  double t[n], t_temp[n];
  int t_index = 0;
  for (int i = 0; i < n; i++) {
    c = f_a[i];
    d[0] = 1;
    t_index = 0;
    for (int j = 0; j < n; j++) {
      if (i != j) {
        c /= (a[i] - a[j]);
        t[t_index] = -a[j];
        t_temp[t_index] = -a[j];
        t_index++;
      }
    }
    d[1] = sum(t, n - 2, n - 1);
    for (int k = 2; k < n; k++) {
      d[k] = 0;
      for (int l = 0; l < n - k; l++) {
        t_temp[l] = t[l] * sum(t_temp, n - k, n - k - l);

        d[k] += t_temp[l];
      }
    }
    for (int m = 0; m < n; m++) {
      l[i][n - m - 1] = d[m] * c;
      // printf("l[%d][%d] = %f,d[%d]=%f,c=%f\n", i, n - m - 1, l[i][n - m -
      // 1],m,d[m], c);
    }
  }
  for (int i = 0; i < n; i++) {
    coeff_f[n - i - 1] = 0;
    for (int j = 0; j < n; j++) {
      coeff_f[n - i - 1] += l[j][n - i - 1];
    }
  }
}

int main(){

    clock_t debut, fin;
    double t_fun_1=0, t_fun_2=0;

    // Initialisation du degré du polynôme n à 1
    int n=1;

    // Boucle principale pour tester différentes tailles de polynômes
    for(int i=0; i<10; i++){ //i allant de 0 à 11 (pour i plus grand ca prend tres longtemps)
        
        // mettre a jour le rang du f (rang 2^i)
        if(i>0){
            n *= 2;
        }
        
        // Allocation et initialisation du tableau de coefficients du polynôme
        double* coeff = malloc((n + 1) * sizeof(double));

        for (int l = 0; l <= n; l++) {
            coeff[l] = 0.0;
        }


        // Allocation et remplissage du tableau des points d'interpolation a avec des valeurs aléatoires
        double* a = malloc((n + 1) * sizeof(double));

        for(int j=0 ; j <= n; j++){
            a[j] = rand()/RAND_MAX *2 -1;
        }

        
        // Allocation et remplissage du tableau des valeurs f_a avec des valeurs aléatoires
        double* f_a = malloc((n + 1) * sizeof(double));

        for(int j=0 ; j <= n; j++){
            f_a[j] = rand()/RAND_MAX *2 -1;
        }


        // Mesure du temps pris par interpol_linalg
        debut = clock();
        interpol_linalg(a, f_a, n, coeff);
        fin = clock();

        t_fun_1 += ((double) (fin - debut)) / CLOCKS_PER_SEC;

        // Mesure du temps pris par interpol_Lagrange
        debut = clock();
        interpol_Lagrange(a, f_a, n, coeff);
        fin = clock();

        t_fun_2 += ((double) (fin - debut)) / CLOCKS_PER_SEC;    

        free(a);
        free(f_a);   
        free(coeff);

    }

    // Affichage des temps d'exécution
    printf("temps prit par interpol_linalg   : %f secondes\n" , t_fun_1);
    printf("temps prit par interpol_Lagrange : %f secondes\n" , t_fun_2);

    return 0;

}