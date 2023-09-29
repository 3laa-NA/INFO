#include<stdlib.h>
#include<stdio.h>

int main(int argc, int const *argv[]){
    int res=0;

	if (argc < 2) {
		printf("arguments manquants\n");
		exit(-1);
	}

    for(int i=1; i<argc;i++){
	    printf("BONJOUR %s !\n", argv[i]);
    }
	return 0;
}