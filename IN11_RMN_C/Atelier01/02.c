#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Question 2

long factorial(uint32_t n)
{
    while (n <= 20)
    {
        if (n == 0)
        {
            return 1;
        }
        else
        {
            return (n * factorial(n - 1));
        }
    }
    return 0;
}

int main()
{
    uint32_t number = 5;
    long fact = factorial(number);
    printf("%d! = %ld\n", number, fact);
    return 0;
}