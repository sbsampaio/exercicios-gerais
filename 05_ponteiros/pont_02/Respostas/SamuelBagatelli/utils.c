#include <stdio.h>
#include "utils.h"

void LeIntervalo(int *m, int *n)
{
    scanf("%d%d", m, n);
}

int EhPrimo(int n)
{
    if (n <= 1 || (n != 2 && n % 2 == 0))
        return 0;

    int i;
    for (i = 3; i < n / 2; i++)
    {
        if (!(n % i))
            return 0;
    }

    return 1;
}

void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior)
{
    *menor = 0;
    for (m; m <= n; m++)
    {
        if (EhPrimo(m))
        {
            if (*menor == 0)
                *menor = m;
            *maior = m;
        }
    }
}