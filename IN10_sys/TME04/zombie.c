#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
    for(int i=0; i<2; i++){
        if(fork()==0){
            printf("Je suis le zombie %d\n", i+1);
            exit(0);
        }
        sleep(10);
        wait(NULL);

    }
    return 0;
}
