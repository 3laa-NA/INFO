#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

// Question 3

typedef struct solution_
{
    int d;
    int x;
    int y;
} Solution;


Solution euclide_etendu(int a, int b)
{
    Solution s;
    Solution tmp;

    if (b == 0)
    {
        s.d = a;
        s.x = 1;
        s.y = 0;

        return s;
    }

    else
    {
        tmp = euclide_etendu(b, a % b);
        s.d = tmp.d;
        s.x = tmp.y;
        s.y = tmp.x - (floor(a / b) * tmp.y);

        return s;
    }
}

int main(void)
{
    int a = 26433;
    int b = 7865;
    Solution s = euclide_etendu(a,b);

    printf("pgcd(%d,%d) = (%d * %d) + (%d * %d) = %d\n",a , b, a, s.x, b, s.y, s.d);

    return 0;
}