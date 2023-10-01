#include<stdlib.h>
#include<stdio.h>

int main(int argc, char const *argv[]){

	//en cas d'appelle sans parametres
	if (argc < 2) {   
		printf("arguments manquants! \nUsage : %ls <liste_noms> \n", argv[0]);
		exit(-1);
	}

	//on parcourt le tableau des parametres(arguments) et on les aditionne a la somme
    for(int i=1; i<argc;i++){
		printf("BONJOUR %s !\n", argv[i]);
    }
	return 0;
}