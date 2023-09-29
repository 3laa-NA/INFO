#include<stdlib.h>
#include<stdio.h>

int main(int argc, char const *argv[]){

	if (argc < 2) {
		printf("arguments manquants! \nUsage : mon_test <des_chaines_de_caractere> \n");
		exit(-1);
	}

    for(int i=1; i<argc;i++){
		printf("BONJOUR %s !\n", argv[i]);
    }
	return 0;
}