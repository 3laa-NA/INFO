#include<stdlib.h>
#include<stdio.h>

int main(int argc, int const *argv[]){
	
	//on initialise la variable où la somme sera stocké
    int res=0;

	//en cas de manque de parametres(arguments)
	if (argc < 2) {
		printf("arguments manquants\nUsage : %ls <des_entiers>\n", argv[0]);
		exit(-1);
	}

	//boucle qui additionne les arguments
    for(int i=1; i<argc;i++){
        res += atoi(argv[i]);
    }

	printf("somme = %d !\n", res);

	return 0;
}