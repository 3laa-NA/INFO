#include<stdlib.h>
#include<stdio.h>

int main(int argc, char const *argv[])
{
    // on affiche le contenu des variables TEST_1 et TEST_2
    printf("TEST_1 : %s\n\n",getenv("TEST_1"));
    printf("TEST_2 : %s\n\n",getenv("TEST_2"));
    return 0;
}
