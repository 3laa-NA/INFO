#include<stdlib.h>
#include<stdio.h>

int main(int argc, char const *argv[])
{
	int i, ret;

	if (argc < 2) {
		printf("Usage : %s <un_entier>\n",argv[0]);
		exit(-1);
	}

	printf("Il %s pair\n", atoi(argv[1]) % 2 ? "n'est pas" : "est");

	return 0;
}

