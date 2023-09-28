#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <fenv.h>

uint32_t add (uint32_t a, uint32_t b, uint32_t p){
    return (a+b)%p;
}

uint32_t sub (uint32_t a, uint32_t b, uint32_t p){
    return (a-b)%p;
}

uint64_t mul (uint32_t a, uint32_t b){
    return a*b;
}

uint64_t mul2 (uint32_t a, uint32_t b, uint32_t p){
    return mul(a,b)%p;
}

uint32_t inv(uint32_t a, uint32_t p) {
    uint32_t u1 = 1, u2 = 0, u3 = p; 
    uint32_t v1 = 0, v2 = 1, v3 = a; 

    while (v3 != 0) {
        uint32_t q = u3 / v3; 
        uint32_t t1 = u1 - q * v1;
        uint32_t t2 = u2 - q * v2;
        uint32_t t3 = u3 - q * v3;

        u1 = v1;
        u2 = v2;
        u3 = v3;
        v1 = t1;
        v2 = t2;
        v3 = t3;
    }


    if (u1 < 0) {
        u1 = u1 + p;
    }

    return u1;
}

int main(){
    uint32_t p = 2;
    uint32_t a = 1;
    uint32_t b = 4;

    printf("pour les valeurs a = %d , b = %d , p = %d :\n",a,b,p);
    printf("add(a, b, p)  = %d \n",add(a, b, p));
    printf("sub(a, b, p)  = %d \n",sub(a, b, p));
    printf("mul(a, b)     = %ld \n",mul(a, b));
    printf("mul2(a, b, p) = %ld \n",mul2(a, b, p));
    printf("inv(a, p)     = %d \n",inv(a, p));

    p = 101;
    a = 10;
    b = 3;

    printf("pour les valeurs a = %d , b = %d , p = %d :\n",a,b,p);
    printf("add(a, b, p)  = %d \n",add(a, b, p));
    printf("sub(a, b, p)  = %d \n",sub(a, b, p));
    printf("mul(a, b)     = %ld \n",mul(a, b));
    printf("mul2(a, b, p) = %ld \n",mul2(a, b, p));
    printf("inv(a, p)     = %d \n",inv(a, p));

    p = 65521;
    a = 413;
    b = 74;

    printf("pour les valeurs a = %d , b = %d , p = %d :\n",a,b,p);
    printf("add(a, b, p)  = %d \n",add(a, b, p));
    printf("sub(a, b, p)  = %d \n",sub(a, b, p));
    printf("mul(a, b)     = %ld \n",mul(a, b));
    printf("mul2(a, b, p) = %ld \n",mul2(a, b, p));
    printf("inv(a, p)     = %d \n",inv(a, p));

    p = 1073741827;
    a = 10903;
    b = 1520;

    printf("pour les valeurs a = %d , b = %d , p = %d :\n",a,b,p);
    printf("add(a, b, p)  = %d \n",add(a, b, p));
    printf("sub(a, b, p)  = %d \n",sub(a, b, p));
    printf("mul(a, b)     = %ld \n",mul(a, b));
    printf("mul2(a, b, p) = %ld \n",mul2(a, b, p));
    printf("inv(a, p)     = %d \n",inv(a, p));


    return 0;
}
