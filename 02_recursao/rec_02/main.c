#include <stdio.h>

/**
 * Realiza a soma dos elementos pares de um vetor
 *
 * @param vet Recebe um vetor de inteiros de tamanho N
 * @param numElementos Recebe o número de elementos N do vetor
 * @return Retorna a soma de todos os elementos pares do vetor
 */
int SomaElementosPares(int *vet, int numElementos);

int main()
{
    int amount = 0;

    scanf("%d\n", &amount);

    while (amount--)
    {
        int numElementos = 0;
        int cont = 0;
        scanf("%d\n", &numElementos);

        int vet[numElementos];

        for (cont = 0; cont < numElementos; cont++)
        {
            scanf("%d\n", &vet[cont]);
        }

        printf("%d\n", SomaElementosPares(vet, numElementos));
    }

    return 0;
}

int SomaElementosPares(int *vet, int numElementos)
{
    if (numElementos <= 0)
        return 0;

    int element = vet[numElementos - 1];

    if (!(element % 2))
        return (element + SomaElementosPares(vet, numElementos - 1));
    else
        return SomaElementosPares(vet, numElementos - 1);
}
