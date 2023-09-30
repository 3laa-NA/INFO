#include<stdlib.h>
#include<stdio.h>

int main(int argc, int const *argv[]){
    int const res=0;

	if (argc < 2) {
		printf("arguments manquants \nUsage : ./somme <des_entiers> \n");
		exit(-1);
	}

    for(int i=1; i<argc;i++){
        res = res + argv[i];
    }

	printf("somme = %d !\n", res);

	return 0;
}