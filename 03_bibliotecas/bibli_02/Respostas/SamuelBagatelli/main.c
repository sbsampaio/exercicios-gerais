#include <stdio.h>
#include "matrix_utils.h"

int main()
{
    int rows1;
    int cols1;
    scanf("%d %d", &rows1, &cols1);

    int matrix1[rows1][cols1];

    matrix_read(rows1, cols1, matrix1);

    int rows2;
    int cols2;
    scanf("%d %d", &rows2, &cols2);

    int matrix2[rows2][cols2];

    matrix_read(rows2, cols2, matrix2);

    while (1)
    {
        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida: \n");

        int option;

        scanf("%d", &option);

        if (option == 1)
        {
            if (!possible_matrix_sum(rows1, cols1, rows2, cols2))
            {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
            else
            {
                int result[rows1][cols1];

                matrix_add(rows1, cols1, matrix1, rows2, cols2, matrix2, result);

                matrix_print(rows1, cols1, result);
            }
        }

        if (option == 2)
        {
            if (!possible_matrix_sub(rows1, cols1, rows2, cols2))
            {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
            else
            {
                int result[rows1][cols1];

                matrix_sub(rows1, cols1, matrix1, rows2, cols2, matrix2, result);

                matrix_print(rows1, cols1, result);
            }
        }

        if (option == 3)
        {
            if (!possible_matrix_multiply(cols1, rows2))
            {
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
            }
            else
            {
                int result[rows1][cols2];

                matrix_multiply(rows1, cols1, matrix1, rows2, cols2, matrix2, result);

                matrix_print(rows1, cols2, result);
            }
        }

        if (option == 4)
        {
            int scalar, to_multiply;

            scanf("%d %d", &scalar, &to_multiply);

            if (to_multiply == 1)
            {
                scalar_multiply(rows1, cols1, matrix1, scalar);

                matrix_print(rows1, cols1, matrix1);
            }
            else
            {
                scalar_multiply(rows2, cols2, matrix2, scalar);

                matrix_print(rows2, cols2, matrix2);
            }
        }

        if (option == 5)
        {
            int result1[cols1][rows1], result2[cols2][rows2];

            transpose_matrix(rows1, cols1, matrix1, result1);

            matrix_print(cols1, rows1, result1);

            transpose_matrix(rows2, cols2, matrix2, result2);

            matrix_print(cols2, rows2, result2);
        }

        if (option == 6)
            break;
    }

    return 0;
}
