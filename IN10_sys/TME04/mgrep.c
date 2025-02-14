#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/resource.h>

#define MAXFILES 3

int main(int argc, char *argv[]){
    
    if(argc < 2){
        printf("Il manque des arguments!\n");
        return 1;
    }

    for(int i=2; i<argc; i++){
        if(i-2 >= MAXFILES){
            wait(NULL);
        }
        if(fork()==0){
            execlp("grep", "grep", argv[1], argv[i], NULL);
        }
    }

    for(int i=2; i<argc && i<MAXFILES+2; i++){
        int status;
        struct rusage usage;
        wait3(&status, 0, &usage);
        printf("\nStatistique d'utilisation de CPU pour le fils %d:\n", i-2);
        printf("Temps CPU utilisateur: %ld.%06ld s\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
        printf("Temps CPU system: %ld.%06ld s\n", usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
    }

    return 0;
}