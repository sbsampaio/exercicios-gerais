#include <stdio.h>
#include <string.h>

/**
 * Verica se a string passada é um palíndromo
 *
 * @param string Recebe uma string qualquer a ser analisada
 * @param tamanho Recebe o tamanho da string
 */
int palindromo(char *string, int tamanho);

int main()
{
    char string[1000];

    while (scanf("%s", string) == 1)
    {
        if (palindromo(string, strlen(string)))
            printf("SIM\n");
        else
            printf("NAO\n");
    }

    return 0;
}

int palindromo(char *string, int tamanho)
{
    if (string[strlen(string) - tamanho] == string[tamanho - 1])
    {
        if (tamanho < (strlen(string) / 2))
            return 1;

        return palindromo(string, tamanho - 1);
    }

    return 0;
}
