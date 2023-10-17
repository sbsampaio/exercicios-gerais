#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int **CriaMatriz(int linhas, int colunas)
{
    int(*mat)[colunas] = calloc(linhas * colunas, sizeof(int));

    if (mat == NULL)
    {
        printf("Problema na alocacao!\n");
        exit(1);
    }

    return (int **)mat;
}

void LiberaMatriz(int **matriz, int linhas)
{
    for (int i = 0; i < linhas; i++)
    {
        free(matriz[i]);
    }

    free(matriz);
}

void LeMatriz(int **matriz, int linhas, int colunas)
{
    int i, j, aux;

    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            scanf("%d", &aux);
            matriz[i][j] = aux;
        }
    }
}

void ImprimeMatrizTransposta(int **matriz, int linhas, int colunas)
{
    int i, j;

    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            printf("%d ", matriz[j][i]);
        }
        printf("\n");
    }
}