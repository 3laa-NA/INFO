#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <fenv.h>


void affiche(double reel)
{
    double x;

    printf("l'arrondi de %f \n",reel);

    fesetround(FE_TOWARDZERO);
    x = reel;
    printf("en mode 'zero'  = %24.15le \n", x);

    fesetround(FE_TONEAREST);
    x = reel;
    printf("en mode 'arr'   = %24.15le \n", x);

    fesetround(FE_DOWNWARD);
    x = reel;
    printf("en mode 'moinf' = %24.15le \n", x);

    fesetround(FE_UPWARD);
    x = reel;
    printf("en mode 'plinf' = %24.15le \n", x);

}

int main(){

    double a = 156.7;
    affiche(a);
    double b = -pow(7.11, -5);
    affiche(b);

    return 0;
}