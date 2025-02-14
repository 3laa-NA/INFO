#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if(argc == 1){
        printf("Il manque les arguments!\n");
        return 1;
    }

    int max = atoi(argv[1]);
    for (int i=2; i<argc; i++){
        int x = atoi (argv[i]);

        if (x>max){
            max = x;
        }
    }

    printf("Le maximum est : %d\n", max);
    
    return 0;
}

