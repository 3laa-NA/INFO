#include<stdlib.h>
#include<stdio.h>

int main(int argc, char const *argv[])
{
	char c;
	int cle;

	if (argc != 2) {
		fprintf(stderr, "Il faut donner une cle\n");
		fprintf(stderr, "Usage : %s <un_entier>\n", argv[0]);
		exit(1);
	}

	cle = atoi(argv[1]);
	while (EOF != (c = fgetc(stdin)))
		if ('a' <= c && c <= 'z')
			printf("%c", 'a' + (c - 'a' + cle) % 26);
		else
			printf("%c", c);

	return 0;
}
