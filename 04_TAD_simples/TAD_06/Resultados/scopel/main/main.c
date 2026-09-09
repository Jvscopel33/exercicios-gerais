#include <stdio.h>
#include "matrix_utils.h"

int main()
{
    int cmd;
    int id;
    int scalar;
    tMatrix m1;
    tMatrix m2;
    scanf("%d %d\n", &m1.rows, &m1.cols);
    m1 = MatrixCreate(m1.rows, m1.cols);
    m1 = MatrixRead(m1);
    scanf("%d %d\n", &m2.rows, &m2.cols);
    m2 = MatrixCreate(m2.rows, m2.cols);
    m2 = MatrixRead(m2);
    while (1)
    {
        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida:\n");
        scanf(" %d\n", &cmd);
        if (cmd == 1)
        {
            if (PossibleMatrixSum(m1, m2))
            {
                MatrixPrint(MatrixAdd(m1, m2));
            }
            else
            {
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }
        }
        else if (cmd == 2)
        {
            if (PossibleMatrixSub(m1, m2))
            {
                MatrixPrint(MatrixSub(m1, m2));
            }
            else
            {
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }
        }

        else if (cmd == 3)
        {
            if (PossibleMatrixMultiply(m1, m2))
            {
                MatrixPrint(MatrixMultiply(m1, m2));
            }
            else
            {
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
            }
        }
        else if (cmd == 4)
        {
            scanf(" %d %d\n", &scalar, &id);
            if (id == 1)
            {
                m1 = MatrixMultiplyByScalar(m1, scalar);
                MatrixPrint(m1);
            }
            else
            {
                m2 = MatrixMultiplyByScalar(m2, scalar);
                MatrixPrint(m2);
            }
        }
        else if (cmd == 5)
        {
            MatrixPrint(TransposeMatrix(m1));
            MatrixPrint(TransposeMatrix(m2));
        }
        else if (cmd == 6)
        {
            break;
        }
    }
    return 0;
}