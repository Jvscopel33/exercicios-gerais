#include <stdio.h>
#include "matrix_utils.h"
// #define MAX_MATRIX_SIZE 10

// typedef struct Matrix{
//     int rows;
//     int cols;
//     int data[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
// } tMatrix;

/**
 * @brief Cria uma matriz com o número de linhas e colunas especificado.
 * @param rows O número de linhas na matriz.
 * @param cols O número de colunas na matriz.
 * @return A matriz criada.
 */
tMatrix MatrixCreate(int rows, int cols)
{
    tMatrix m;
    m.cols = cols;
    m.rows = rows;
    for (int i = 0; i < m.rows; i++)
    {
        for (int j = 0; j < m.cols; j++)
        {
            m.data[i][j] = 0;
        }
    }
    return m;
}

/**
 * @brief Lê uma matriz da entrada padrão.
 * @param matrix A matriz a ser lida.
 * @return A matriz lida.
 */

tMatrix MatrixRead(tMatrix matrix)
{
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.cols; j++)
        {
            scanf(" %d", &matrix.data[i][j]);
        }
    }
    return matrix;
}

/**
 * @brief Imprime uma matriz na saída padrão.
 * @param matrix A matriz a ser impressa.
 */
void MatrixPrint(tMatrix matrix)
{
    for (int i = 0; i < matrix.rows; i++)
    {
        printf("|");
        for (int j = 0; j < matrix.cols; j++)
        {
            if (j > 0)
            {
                printf(" %d", matrix.data[i][j]);
            }
            else
            {
                printf("%d", matrix.data[i][j]);
            }
        }
        printf("|");
        printf("\n");
    }
}

/**
 * @brief Verifica se é possível somar duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível somar as matrizes, 0 caso contrário.
 */
int PossibleMatrixSum(tMatrix matrix1, tMatrix matrix2)
{
    if (matrix1.cols == matrix2.cols && matrix1.rows == matrix2.rows)
    {
        return 1;
    }
    return 0;
}

/**
 * @brief Verifica se é possível subtrair duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível subtrair as matrizes, 0 caso contrário.
 */
int PossibleMatrixSub(tMatrix matrix1, tMatrix matrix2)
{
    if (matrix1.cols == matrix2.cols && matrix1.rows == matrix2.rows)
    {
        return 1;
    }
    return 0;
}

/**
 * @brief Verifica se é possível multiplicar duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível multiplicar as matrizes, 0 caso contrário.
 */
int PossibleMatrixMultiply(tMatrix matrix1, tMatrix matrix2)
{
    if (matrix1.rows == matrix2.cols)
    {
        return 1;
    }
    return 0;
}

/**
 * @brief Soma duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da soma.
 */
tMatrix MatrixAdd(tMatrix matrix1, tMatrix matrix2)
{
    tMatrix msum;
    msum = MatrixCreate(matrix1.rows, matrix2.cols);
    for (int i = 0; i < msum.rows; i++)
    {
        for (int j = 0; j < msum.cols; j++)
        {
            msum.data[i][j] = matrix1.data[i][j] + matrix2.data[i][j];
        }
    }
    return msum;
}

/**
 * @brief Subtrai duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da subtração.
 */
tMatrix MatrixSub(tMatrix matrix1, tMatrix matrix2)
{
    tMatrix msub;
    msub = MatrixCreate(matrix1.rows, matrix2.cols);
    for (int i = 0; i < msub.rows; i++)
    {
        for (int j = 0; j < msub.cols; j++)
        {
            msub.data[i][j] = matrix1.data[i][j] - matrix2.data[i][j];
        }
    }
    return msub;
}

/**
 * @brief Multiplica duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da multiplicação.
 */
tMatrix MatrixMultiply(tMatrix matrix1, tMatrix matrix2)
{
    tMatrix m;
    m = MatrixCreate(matrix1.rows, matrix2.cols);
    for (int i = 0; i < matrix1.rows; i++)
    {
        for (int j = 0; j < matrix2.cols; j++)
        {
            for (int k = 0; k < matrix1.cols; k++)
            {
                m.data[i][j] += matrix1.data[i][k] * matrix2.data[k][j];
            }
        }
    }
    return m;
}

/**
 * @brief Transpõe uma matriz.
 * @param matrix A matriz a ser transposta.
 * @return A matriz transposta.
 */
tMatrix TransposeMatrix(tMatrix matrix)
{
    tMatrix mT;
    mT = MatrixCreate(matrix.cols, matrix.rows);
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.cols; j++)
        {
            mT.data[j][i] = matrix.data[i][j];
        }
    }
    return mT;
}

/**
 * @brief Multiplica uma matriz por um escalar.
 * @param matrix A matriz a ser multiplicada.
 * @param scalar O escalar pelo qual a matriz será multiplicada.
 * @return O resultado da multiplicação.
 */
tMatrix MatrixMultiplyByScalar(tMatrix matrix, int scalar)
{
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.cols; j++)
        {
            matrix.data[i][j] = matrix.data[i][j] * scalar;
        }
    }
    return matrix;
}
