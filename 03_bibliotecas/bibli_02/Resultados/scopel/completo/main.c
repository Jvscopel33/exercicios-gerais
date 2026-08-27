#include <stdio.h>
#include "matrix_utils.h"
#define MAX_COLS 100
#define MAX_ROWS 100
int main()
{

    int rows1, rows2, cols1, cols2;
    scanf("%d %d", &rows1, &cols1);
    int matrix1[rows1][cols1];
    matrix_read(rows1, cols1, matrix1);
    scanf("%d %d", &rows2, &cols2);
    int matrix2[rows2][cols2];
    matrix_read(rows2, cols2, matrix2);
    int option;
    while (1)
    {
        printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n5 - Transposta de uma matriz\n6 - Encerrar o programa\nOpcao escolhida: \n");
        scanf("%d", &option);
        if (option == 6)
        {
            return 0;
        }
        else if (option == 1)
        {
            if (possible_matrix_sum(rows1, cols1, rows2, cols2))
            {
                int result[rows1][cols1];
                matrix_add(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
                matrix_print(rows1, cols1, result);
            }
            else
            {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
                continue;
            }
        }
        else if (option == 2)
        {
            if (possible_matrix_sub(rows1, cols1, rows2, cols2))
            {
                int result[rows1][cols1];
                matrix_sub(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
                matrix_print(rows1, cols1, result);
            }
            else
            {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
                continue;
            }
        }
        else if (option == 3)
        {
            if (possible_matrix_multiply(cols1, rows2))
            {
                int result[rows1][cols2];
                matrix_multiply(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
                matrix_print(rows1, cols2, result);
            }
            else
            {
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
                continue;
            }
        }
        else if (option == 4)
        {
            int scalar, matriz;
            scanf("%d %d", &scalar, &matriz);
            if (matriz == 1)
            {
                scalar_multiply(rows1, cols1, matrix1, scalar);
                matrix_print(rows1, cols1, matrix1);
            }
            else if (matriz == 2)
            {
                scalar_multiply(rows2, cols2, matrix2, scalar);
                matrix_print(rows2, cols2, matrix2);
            }
        }
        else if (option == 5)
        {
            int result1[rows1][cols1];
            int result2[rows2][cols2];
            transpose_matrix(rows1, cols1, matrix1, result1);
            transpose_matrix(rows2, cols2, matrix2, result2);
            matrix_print(cols1, rows1, result1);
            matrix_print(cols2, rows2, result2);
        }
    }
    return 0;
}