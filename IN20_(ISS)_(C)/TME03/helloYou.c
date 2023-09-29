#include<stdlib.h>
#include<stdio.h>

int main(int argc, char const *argv[]){

	if (argc < 2) {
		printf("arguments manquants\n");
		exit(-1);
	}

    for(int i=1; i<argc;i++){
	    printf("HELLO %s !\n", argv[i]);
    }
	return 0;
}