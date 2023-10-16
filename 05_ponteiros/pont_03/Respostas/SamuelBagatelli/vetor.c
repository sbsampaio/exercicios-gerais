#include <stdio.h>
#include "vetor.h"

void LeDadosParaVetor(int *vet, int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        scanf("%d", (vet + i));
    }
}

void ImprimeDadosDoVetor(int *n, int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        printf("%d ", *(n + i));
    }
    printf("\n");
}

void TrocaSeAcharMenor(int *vet, int tam, int *paraTrocar)
{
    int i, j, aux;
    for (i = tam - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (vet[j] < vet[j + 1])
                aux = vet[j];
        }
    }

    if (aux < *paraTrocar)
        *paraTrocar = aux;
}

void OrdeneCrescente(int *vet, int tam)
{
    int i, j, aux;
    for (i = tam - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (vet[j] > vet[j + 1])
            {
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
        }
    }
}