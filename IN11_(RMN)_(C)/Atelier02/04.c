#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fenv.h>
#include <math.h>

double archimede1(int k){
    if(k==2){
        return sqrt(2);
    }

    else{
        return sqrt(2*(1 - sqrt(1 - (pow(archimede1(k-1),2)/4))));
    }
}

double archimede2(int k){

    if(k==2){
        return sqrt(2);
    }

    else{
        return sqrt( ( ( pow(archimede1(k-1),2)/4 ) / (2 * (1 + sqrt(1 - (pow(archimede1(k-1),2)/4)))) ) * 4 );
    }

}

int main(){

    int x = 29;

    double a = pow(2,x-1) * archimede1(x);
    printf("Approximation de π avec la première formule  %.15f \n",a);

    double b = pow(2,x-1) * archimede2(x);
    printf("Approximation de π avec la deuxième formule  %.15f \n",b);

    printf("Valeur réelle de π (M_PI) :                  %.15lf\n", M_PI);

    return 0;
}
