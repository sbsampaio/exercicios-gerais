#include <stdio.h>

/**
 * @brief Calcula o fatorial de um número
 * @param n Número inteiro não negativo
 * @return Fatorial de n
*/
int fatorial(int n);

int main()
{
    int n;

    scanf("%d", &n);

    printf("%d\n", fatorial(n));

    return 0;
}

int fatorial(int n)
{
    if (n > 1)
        return n * fatorial(n - 1);
    
    return 1;
}