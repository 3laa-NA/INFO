#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

/*
Groupe:
Dicko Daouda
Mohamed Ichraq
Alaboud Alaa
Diakite Gaoussou
*/

void split_64 (uint64_t a, uint32_t *a1, uint32_t *a0){
    uint32_t x=0;
    uint64_t z=a;

    while(z>=pow(2,31)){
        x++;
        z-=pow(2,31);
    }

    *a1=x;
    *a0=(uint32_t)z;
}

void mul_naive_128 (uint64_t a, uint64_t b, uint64_t *ab2, uint64_t *ab1, uint64_t *ab0){
    uint32_t a0,a1,b0,b1;
    split_64(a,&a0,&a1);
    split_64(b,&b0,&b1);

    *ab2 = a1*b1;
    *ab1 = (a1*b0) + (a0*b1);
    *ab0 = a0*b0;
}

void mul_karatsuba_128 (uint64_t a, uint64_t b, uint64_t *ab2, uint64_t *ab1, uint64_t *ab0){
    uint32_t a0,a1,b0,b1;
    split_64(a,&a0,&a1);
    split_64(b,&b0,&b1);

    *ab2 = a1*b1;
    *ab0 = a0*b0;
    *ab1 = (a1+a0) * (b1*b0) - *ab2 - *ab0;
}


int main() {
    uint64_t a = 123456789012345;
    uint64_t b = 987654321098765;
    uint64_t ab2, ab1, ab0;

    printf("pour les valeurs a = %ld , b = %ld :\n",a,b);
    uint32_t a1, a0;
    split_64(a, &a1, &a0);
    printf("split_64(a)             = a1: %u, a0: %u\n", a1, a0);

    uint32_t b1, b0;
    split_64(b, &b1, &b0);
    printf("split_64(b)             = b1: %u, b0: %u\n", b1, b0);

    mul_naive_128(a, b, &ab2, &ab1, &ab0);
    printf("mul_naive_128(a, b)     = ab2: %lu, ab1: %lu, ab0: %lu\n", ab2, ab1, ab0);

    mul_karatsuba_128(a, b, &ab2, &ab1, &ab0);
    printf("mul_karatsuba_128(a, b) = ab2: %lu, ab1: %lu, ab0: %lu\n", ab2, ab1, ab0);

    return 0;
}