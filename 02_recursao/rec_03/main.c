#include <stdio.h>

/**
 * Conta ocorrências de um determinado número dentro de um vetor;
 *
 * @param vet Recebe o vetor a ser analisado
 * @param numElementos Recebe o número de elementos - tamanho - do vetor
 * @param numeroProcurado Recebe o número a ser procurado no vetor
 * @return Retorna a quantidade de ocorrências do número no vetor
 */
int ContaOcorrencias(int *vet, int numElementos, int numeroProcurado);

int main()
{
    int casos;

    scanf("%d", &casos);

    int numeroProcurado;
    int numElementos;

    int i;

    while (casos--)
    {
        scanf("%d %d", &numeroProcurado, &numElementos);

        int vet[numElementos];

        for (i = 0; i < numElementos; i++)
        {
            int n;

            scanf("%d", &n);

            vet[i] = n;
        }

        printf("%d\n", ContaOcorrencias(vet, numElementos, numeroProcurado));
    }

    return 0;
}

int ContaOcorrencias(int *vet, int numElementos, int numeroProcurado)
{
    if (numElementos > 0)
    {
        if (vet[numElementos - 1] == numeroProcurado)
            return 1 + ContaOcorrencias(vet, numElementos - 1, numeroProcurado);

        return ContaOcorrencias(vet, numElementos - 1, numeroProcurado);
    }

    return 0;
}
