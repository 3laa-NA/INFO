#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


void mulpol (double* coeff_f, int n, double* coeff_g, int p, double* coeff_h, int* q){

    double *tmp= malloc(sizeof(double) * (n+p+1));

    for(int i=0; i<= n; i++){

        if(coeff_f[i]!=0){

            for(int j=0; j<= p; j++){
                if(coeff_g[j]!=0){
                    tmp[i+j] += coeff_f[i] * coeff_g[j]; // Stockage du terme dans le résultat
                }

            } 

        }

    }
    
    *q = n+p; //rang de h = (rang de f) + (ranf de g)

    for(int g=0; g <= *q; g++){
        coeff_h[g] = tmp[g];
    }

    free(tmp);

}

void gauss_sp(double *a, double *b, int n) {

    for (int i = 0; i < n; i++) {

        // Étape de normalisation pour rendre l'élément diagonal égal à 1
        double pivot = a [i*n +i];  // Élément diagonal
        for (int j = i; j < n; j++) {
            a  [i*n + j] /= pivot;  // Normalisation de la ligne i
        }

        b[i] /= pivot;  // Normalisation du vecteur second membre

        // Étape d'élimination pour rendre les éléments en dehors de la diagonale égaux à 0
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = a [k*n + i];  // Facteur d'élimination
                for (int j = i; j < n; j++) {
                    a [k*n + j] -= factor * (*(a + i * n + j));  // Élimination des éléments
                }
                b[k] -= factor * b[i];  // Mise à jour du vecteur second membre
            }
        }
    }
}


void interpol_linalg (double* a, double* f_a, int n, double* coeff_f){

    double *mat = malloc( sizeof(double)* ((n+1)*(n+1)) );

    // Construction de la matrice
    for(int i = 0; i<= n; i++){

        mat[i*(n + 1)] = 1.0;

        // Calcul des puissances de a[i] pour chaque colonne
        for(int j = 1; j<= n; j++){
            //mat[i*n +j] = mat[i*n +j-1] * a[i];
            mat[i*(n+1)+j] = mat[i*(n+1)+j-1]*a[i];
        }

    }

    // Résolution du système linéaire par la méthode de Gauss
    gauss_sp(mat,f_a,n);
    
    // Copie des coefficients dans le résultat
    for(int i=0; i<n; i++){
        coeff_f[i] = f_a[i];
    }

    free(mat);

}

void  multipointeval_linalg(double *a, double* coeff_f, int n, double* f_a){

    // A FINIR
    
}


void interpol_Lagrange (double* a, double* f_a, int n, double* coeff_f){

    for(int i=0; i<=n; i++){

        double deno = 1; //dénominateur de Li
        double *nume = malloc (sizeof(double)*(n+1)); //numérateur de Li (polynome)

        for (int g = 0; g<=n; g++){
            nume[g] = 0.0;
        }

        nume[0] = 1;

        for(int j=0; j<=n; j++){
            
            if(j!=i){

                for (int k=n-1; k>=0 ; k--){
                    if(nume[k]!=0.0){
                        nume[k+1] += nume[k]; //on augmente le rang de coefficient (on simule la multiplication par X)
                        nume[k] = -a[j]; //(on simule -xj ))
                    }
                }

                deno *= (a[i] - a[j]); // on met à jour le dénominateur
            }

        }

        //sommer
        for(int l=0; l<=n; l++){
            coeff_f[l] += f_a[i]* (nume[l]/deno);
        }

        free(nume);

    }

}


/*void interpol_Lagrange (double* a, double* f_a, int n, double* coeff_f){

    for(int i=0; i<=n; i++){

        double deno = 1; //dénominateur de Li
        double *nume = malloc (sizeof(double)*(n+1)); //numérateur de Li (polynome)

        for (int g = 0; g<=n; g++){
            nume[g] = 0.0;
        }

        nume[0] = 1;
        int dgr = 0;

        for(int j=0; j<=n; j++){
            
            if(j!=i){

                double snd_term[] = {a[j], 1};

                mulpol(nume, dgr, snd_term, 1, nume, &dgr);

                deno *= (a[i] - a[j]); // on met à jour le dénominateur
            }

        }

        //sommer
        for(int l=0; l<=n; l++){
            coeff_f[l] += f_a[i]* (nume[l]/deno);
        }

        free(nume);

    }

}*/

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