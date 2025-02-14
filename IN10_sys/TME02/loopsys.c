#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>


int main(void) {

    for (int i = 0; i < 5*pow(10,6); i++){
        getpid();
    }

    return 0;
}


