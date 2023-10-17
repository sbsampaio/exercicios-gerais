#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main(int argc, char *argv[])
{
    int linhas, colunas;

    scanf("%d%d", &linhas, &colunas);

    int **mat = CriaMatriz(linhas, colunas);

    LeMatriz(mat, linhas, colunas);

    ImprimeMatrizTransposta(mat, linhas, colunas);

    LiberaMatriz(mat, linhas);

    return 0;
}
