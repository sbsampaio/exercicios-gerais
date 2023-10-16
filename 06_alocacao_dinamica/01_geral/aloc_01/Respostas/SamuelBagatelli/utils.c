#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int *CriaVetor(int tamanho)
{
    int *pV = (int *)malloc(tamanho * sizeof(int));
    if (pV == NULL)
    {
        printf("Problema na alocacao!\n");
        exit(1);
    }

    return pV;
}

void LeVetor(int *vetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &vetor[i]);
    }
}

float CalculaMedia(int *vetor, int tamanho)
{
    float media = 0.0;

    for (int i = 0; i < tamanho; i++)
    {
        media += vetor[i];
    }

    return (media / tamanho);
}

void LiberaVetor(int *vetor)
{
    free(vetor);
}