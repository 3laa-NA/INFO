#include <stdio.h>
#include <time.h>

#define N 100000
#define RAND_MAX 115

int bitcommun(double x, double y) {
    long long bx = *((long long*)&x);
    long long by = *((long long*)&y);

    int count = 0;
    for (int i = 0; i < 64; i++) {
        if (((bx >> i) & 1) == ((by >> i) & 1)) {
            count++;
        }
    }
    return count;
}


int bitcommun_opt(double x, double y) {
    long long bx = *((long long*)&x);
    long long by = *((long long*)&y);

    long long xor_result = bx ^ by;
    int count = 0;
    
    while (xor_result != 0) {
        if (xor_result & 1) {
            count++;
        }
        xor_result >>= 1;
    }

    return count;
}


int main() {

    double x[N], y[N],un=1;
    for(int i=0; i< N; i++){
        x[i] = (un*rand()*10000)/RAND_MAX;
        y[i] = x[i] + (un*rand()*0.0001)/RAND_MAX;
    }


    printf("Nombre de bits en commun : %d\n", bitcommun(-2.69998756, -2.70001234));

     
    printf("Nombre de bits en commun (optimise) : %d\n", bitcommun_opt(-2.69998756, -2.70001234));

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    for (int i = 0; i < N; i++) {
        int common_bits = bitcommun(x[i], y[i]);
    }
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Temps pour bitcommun : %f secondes\n", cpu_time_used);

    start = clock();
    for (int i = 0; i < N; i++) {
        int common_bits = bitcommun_opt(x[i], y[i]);
    }
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Temps pour bitcommun_opt : %f secondes\n", cpu_time_used);

    return 0;
}

