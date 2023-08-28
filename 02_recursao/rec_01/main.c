#include <stdio.h>
#include <string.h>

/**
 * Função que recebe uma string como parâmetro e a imprime invertida;
 *
 * @param string Recebe uma string qualquer;
 */
void ImprimeInvertido(char *string);

int main()
{
    char string[1000];

    while (scanf("%s", string) == 1)
    {
        ImprimeInvertido(string);
        printf(" ");
    }

    return 0;
}

void ImprimeInvertido(char *string)
{
    long unsigned int len = strlen(string);

    if (string[len - 1] != '\0')
    {
        printf("%c", string[len - 1]);
        string[len - 1] = '\0';
        ImprimeInvertido(string);
    }
}