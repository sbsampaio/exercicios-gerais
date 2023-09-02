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

    return 0;
}
