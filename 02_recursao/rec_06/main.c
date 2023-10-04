#include <stdio.h>

#define ZERO 0
#define UM 1

/**
 * @brief Calcula o N-ésimo número da sequência de Fibonacci
 * @param n A posição do número esperado na sequência
 * @return O número de posição n na sequência de Fibonacci
 */
int fibonacci(int n);

int main()
{
    int n;

    scanf("%d", &n);

    printf("%d\n", fibonacci(n));

    return 0;
}

int fibonacci(int n)
{
    if (n > 2)
        return fibonacci(n - 1) + fibonacci(n - 2);

    if (n == 0)
        return ZERO;

    return ZERO + UM;
}
