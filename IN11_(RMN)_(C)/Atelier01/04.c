#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

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
        s.y = tmp.x - (a / b) * tmp.y;

        return s;
    }
}

int main(void)
{
    // Système d'équations modulaires
    int equations[3][2] = {{17, 3}, {11, 4}, {6, 5}};
    int solution = 0;
    int modulo = 1;

    for (int i = 0; i < 3; i++)
    {
        modulo *= equations[i][0];
    }

    for (int i = 0; i < 3; i++)
    {
        int ai = equations[i][0];
        int bi = equations[i][1];
        int Mi = modulo / ai;
        Solution s = euclide_etendu(Mi, ai);
        solution += bi * s.x * Mi;
    }

    // Assurez-vous que la solution est positive
    while (solution < 0)
    {
        solution += modulo;
    }

    printf("La fortune minimale que peut espérer le chef du groupe est %d pièces d'or.\n", solution);

    return 0;
}
