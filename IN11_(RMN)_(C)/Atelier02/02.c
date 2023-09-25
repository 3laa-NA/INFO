#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fenv.h>
#include <math.h>


double suite_a(int i){

    if (i==0){
        return 11.0/2.0;
    }
    if (i==1){
        return 61.0/11.0;
    }

    return 111.0 - (1130.0 / suite_a(i-1)) + (3000.0 / (suite_a(i-2) * suite_a(i-1)) );
}

int main(){

    fesetround(FE_TOWARDZERO);
    printf("en mode 'zero' : \n");
    for(int i = 0; i<20;i++){
        printf("a[%d] = %f \n", i+1, suite_a(i));
    }

    fesetround(FE_TONEAREST);
    printf("\nen mode 'arr' : \n");
    for(int i = 0; i<20;i++){
        printf("a[%d] = %f \n", i+1, suite_a(i));
    }

    fesetround(FE_DOWNWARD);
    printf("\nen mode 'moinf' : \n");
    for(int i = 0; i<20;i++){
        printf("a[%d] = %f \n", i+1, suite_a(i));
    }

    fesetround(FE_UPWARD);
    printf("\nen mode 'plinf' : \n");
    for(int i = 0; i<20;i++){
        printf("a[%d] = %f \n", i+1, suite_a(i));
    }

    return 0;
}

