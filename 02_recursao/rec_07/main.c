#include <stdio.h>

/**
 * @brief Calcula a soma dos digitos de n
 * @param n Número inteiro não negativo
 * @return Soma dos digitos de n
 */
int somaDigitos(int n);

int main()
{
    int n;

    scanf("%d", &n);

    printf("%d\n", somaDigitos(n));

    return 0;
}

int somaDigitos(int n)
{
    if (n > 0)
        return (n % 10) + somaDigitos(n / 10);

    return 0;
}