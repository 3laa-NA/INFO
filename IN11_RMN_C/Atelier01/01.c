#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
int pui2[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};

int32_t base_10(int x)
{
    int pui2[] = {};
    for (int i = 0; i < 33; i++)
    {
        pui2[i] = 2 ^ i;
    }

    int32_t val = x;
    int32_t res = 0;

    if (val >= pui2[30])
    {
        printf("Le nombre est trop grand !\n");
        return pui2[30];
    }

    for (int i = 30; i >= 0; i--)
    {
        if (val >= pui2[i])
        {
            val = val - pui2[i];
            res = res * 10 + 1;
        }
        else
        {
            res = res * 10;
        }
    }

    return res;
}

int main()
{
    int32_t x = 1023;
    int32_t res = base_10(x);
    printf("%d\n", res);
    return 0;
} 

*/

// Question 1

int main()
{
    int a, b;
    char c[32]; // Utilisez un tableau de caractères pour stocker la représentation binaire

    printf("CONVERTISSEUR DE BASE 10 EN BASE 2\n\n");
    printf("Entrez le nombre en base 10 que vous souhaitez convertir : ");
    scanf("%d", &a);

    int i = 0; // Initialisation du compteur pour l'indice du tableau

    while (a != 0)
    {
        b = a % 2;
        a = a / 2;
        c[i] = '0' + b; // Convertir l'entier en caractère et le stockez dans le tableau
        i++;            // Incrémentation de l'indice du tableau
    }

    if (i == 0)
    {
        c[i] = '0'; // Cas spécial pour l'entrée 0
        i++;
    }

    printf("Représentation binaire : ");

    // Ecrire dans l'ordre inverse pour obtenir la bonne sortie
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%c", c[j]);
    }

    printf("\n");
    return 0;
}
