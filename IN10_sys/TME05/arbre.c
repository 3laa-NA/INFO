#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Il manque L\n");
        return 1;
    }

    int L = atoi(argv[1]);

    if (L < 1) {
        sleep(30);
        exit(1);
    }

    char buf[10];
    sprintf(buf, "%d", L - 1);

    for (int i=0; i<2;i++){
        
        pid_t pid1 = fork();
        if (pid1 < 0) {
            perror("fork failed");
            exit(1);
        }
        if (pid1 == 0) {
            execl("./arbre", "arbre", buf, NULL);
            perror("execl failed");
            exit(1);
        }
    }

    sleep(30);

    wait(NULL);
    wait(NULL);

    return 0;
}
