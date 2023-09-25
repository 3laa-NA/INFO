#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fenv.h>
#include <math.h>

void solution(double a, double b, double c, double *racines){

    double delta= pow(b,2) - (4*a*c);

    if(delta>=0){
        racines[0]=(-b+sqrt(delta))/(2*a);
        racines[1]=(-b-sqrt(delta))/(2*a);
    }

    else{
        racines[0] = racines[1] = 0.0;
    }
}

void afficher_solutions(double a, double b, double c){

    double racines[2];
    solution(a, b, c, racines);

    printf("les solutions de l'equation (%.2f*X^2) + (%.2f*X) + (%.2f) sont : %.10f et %.10f \n", a, b, c, racines[0], racines[1]);

}

int main(){

    fesetround(FE_TOWARDZERO);
    printf("en mode 'zero' : \n");
    afficher_solutions(3.1, -21000.0, 3.675);

    fesetround(FE_TONEAREST);
    printf("\nen mode 'arr' : \n");
    afficher_solutions(3.1, -21000.0, 3.675);

    fesetround(FE_DOWNWARD);
    printf("\nen mode 'moinf' : \n");
    afficher_solutions(3.1, -21000.0, 3.675);

    fesetround(FE_UPWARD);
    printf("\nen mode 'plinf' : \n");
    afficher_solutions(3.1, -21000.0, 3.675);

    return 0;
}