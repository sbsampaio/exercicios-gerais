#include <stdio.h>

/**
 * @brief Lê um vetor da entrada principal
 * @param tam O tamanho do vetor
 * @param vetor O vetor a ser lido
 */
void LeVetor(int tam, int vetor[tam]);

/**
 * @brief Verifica se um vetor possui elementos iguais e imprime esses elementos na saída padrão
 * @param tam O tamanho do vetor
 * @param vetor O vetor a ser analisado
 */
void ImprimeNumerosUnicos(int tam, int vetor[tam], int unicos[tam]);

/**
 * @brief Inicializa um vetor atribuindo zero à todas as posições
 * @param tam Tamanho do vetor
 * @param vetor Vetor a ser inicializado
 */
void InicializaVetor(int tam, int vetor[tam]);

/**
 * @brief BubbleSort algoritimo
 * @param tam Tamanho do vetor a ser organizado
 * @param vetor Vetor a ser organizado
 */
void BubbleSort(int tam, int vetor[tam]);

int main()
{
    int tam;
    scanf("%d", &tam);

    int vetor[tam];
    LeVetor(tam, vetor);

    int unicos[tam];
    InicializaVetor(tam, unicos);

    ImprimeNumerosUnicos(tam, vetor, unicos);
}

void LeVetor(int tam, int vetor[tam])
{
    int i;

    for (i = 0; i < tam; i++)
    {
        scanf("%d", &vetor[i]);
    }
}

void ImprimeNumerosUnicos(int tam, int vetor[tam], int unicos[tam])
{
    int i, j;
    int unico;

    for (i = 0; i < tam; i++)
    {
        unico = 1;

        for (j = 0; j < tam; j++)
        {
            if (vetor[i] == vetor[j] && i != j)
                unico = 0;
        }

        if (unico)
            unicos[i] = vetor[i];
    }

    BubbleSort(tam, unicos);

    int cont = 0;

    for (i = 0; i < tam; i++)
    {
        if (unicos[i] != 0)
            printf("%d ", unicos[i]);
        else
            cont++;
    }

    if (cont == tam)
        printf("NENHUM");
}

void InicializaVetor(int tam, int vetor[tam])
{
    int i;

    for (i = 0; i < tam; i++)
    {
        vetor[i] = 0;
    }
}

void BubbleSort(int tam, int vetor[tam])
{
    int i, j;
    int temp;
    for (i = 0; i < tam - 1; i++)
    {
        for (j = 0; j < tam - i - 1; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}