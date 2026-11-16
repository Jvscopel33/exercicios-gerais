#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matrizgenerica.h"


// Adaptado do código compartilhado pelo prof. Thiago

struct matrizgenerica
{
    int linhas;
    int colunas;
    int numByElem;
    void ***data;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar uma Matriz de qualquer tipo de dados,
 * desde que esse tipo ocupe determinado número de bytes.
 *
 * @param linhas - Numero de linhas da matriz
 * @param colunas - Numero de colunas da matriz
 * @param numByteElem - Número de Bytes que cada elemento da matriz ocupará
 *
 * @return Um ponteiro para a estrutura que armazena uma matriz genérica
 */

tMatrizGenerica *CriaMatrizGenerica(int linhas, int colunas, int numByteElem)
{
    if (linhas <= 0 || colunas <= 0 || numByteElem <= 0)
        return NULL;

    tMatrizGenerica *m = calloc(1, sizeof *m);
    if (!m)
        return NULL;

    m->linhas = linhas;
    m->colunas = colunas;
    m->numByElem = numByteElem;
    m->data = calloc(linhas, sizeof *m->data);

    if (!m->data)
        goto falha;

    for (int i = 0; i < linhas; i++)
    {
        m->data[i] = calloc(colunas, sizeof *m->data[i]);
        if (!m->data[i])
            goto falha;

        for (int j = 0; j < colunas; j++)
        {
            m->data[i][j] = malloc(numByteElem);
            if (!m->data[i][j])
                goto falha;
        }
    }

    return m;

falha:
    DestroiMatrizGenerica(m);
    return NULL;
}

/**
 * @brief Libera a memória alocada dinamicamente para uma matriz
 *
 * @param mat - Ponteiro para a matriz a ser liberada
 *
 */
void DestroiMatrizGenerica(tMatrizGenerica *mat)
{
    if (!mat)
        return;

    if (mat->data)
    {
        for (int i = 0; i < mat->linhas && mat->data[i]; i++)
        {
            for (int j = 0; j < mat->colunas; j++)
                free(mat->data[i][j]);

            free(mat->data[i]);
        }
        free(mat->data);
    }
    free(mat);
}

/**
 * @brief Obtém o número de linhas da matriz
 *
 * @param mat - Ponteiro para a matriz que queremos saber o número de linhas
 *
 * @return O número de linhas da matriz
 */
int ObtemNumeroLinhasMatrizGenerica(tMatrizGenerica *mat)
{
    return mat ? mat->linhas : 0;
}

/**
 * @brief Obtém o número de colunas da matriz
 *
 * @param mat - Ponteiro para a matriz que queremos saber o número de colunas
 *
 * @return O número de colunas da matriz
 */
int ObtemNumeroColunasMatrizGenerica(tMatrizGenerica *mat)
{
    return mat ? mat->colunas : 0;
}

/**
 * @brief Obtém ponteiro para um elemento qualquer da matriz genérica.
 *
 * @param mat - Ponteiro para a matriz que queremos encontrar o elemento na linha e coluna desejada
 * @param linha - Linha que o elemento está
 * @param coluna - Coluna que o elemento está
 *
 * @return Ponteiro para o elemento da matriz que está na linha e coluna passadas como parâmetro
 */
void *ObtemElementoMatrizGenerica(tMatrizGenerica *mat, int linha, int coluna)
{
    if (!mat || linha < 0 || linha >= mat->linhas ||
        coluna < 0 || coluna >= mat->colunas)
        return NULL;

    return mat->data[linha][coluna];
}

/**
 * @brief Atribui um elemento a uma posição de uma matriz.
 *
 * @param mat - Ponteiro para a matriz que queremos atribuir o elemento na linha e coluna desejada
 * @param linha - Linha que o elemento ficará
 * @param coluna - Coluna que o elemento ficará
 * @param elem - Ponteiro para o elemento que será colocado na matriz (será feita uma cópia)
 *
 */
void AtribuiElementoMatrizGenerica(tMatrizGenerica *mat, int linha, int coluna, void *elem)
{
    void *destino = ObtemElementoMatrizGenerica(mat, linha, coluna);
    if (destino && elem)
        memmove(destino, elem, mat->numByElem);
}

/**
 * @brief Imprime os elementos usando um callback para imprimir o tipo de dados da matriz.
 * A matriz é impressa linha a linha: após cada elemento (inclusive o último da linha) é impresso um espaço
 * e, ao final de cada linha, uma quebra de linha ('\n'). O callback deve imprimir apenas o elemento,
 * sem espaços ou quebras de linha.
 *
 * @param mat - Ponteiro para a matriz que queremos atribuir o elemento na linha e coluna desejada
 * @param imprime_elemento - Ponteiro para a função (callback) que tem a capacidade de imprimir os dados de um elemento desta matriz
 */

void ImprimirMatrizGenerica(tMatrizGenerica *mat, void (*imprime_elemento)(void *))
{
    if (!mat || !imprime_elemento)
        return;

    for (int i = 0; i < mat->linhas; i++)
    {
        for (int j = 0; j < mat->colunas; j++)
        {
            imprime_elemento(mat->data[i][j]);
            putchar(' ');
        }
        printf("\n");
    }
}

/**
 * @brief Encontra a transposta de uma matriz passada como parâmetro
 *
 * @param mat - A matriz que queremos encontrar a transposta
 *
 * @return Ponteiro para uma nova matriz, igual à transposta da matriz mat
 */
tMatrizGenerica *MatrizTransposta(tMatrizGenerica *mat)
{
    if (!mat)
        return NULL;

    tMatrizGenerica *tra = CriaMatrizGenerica(mat->colunas, mat->linhas, mat->numByElem);
    if (!tra)
        return NULL;

    for (int i = 0; i < mat->linhas; i++)
    {
        for (int j = 0; j < mat->colunas; j++)
        {
            AtribuiElementoMatrizGenerica(tra, j, i, mat->data[i][j]);
        }
    }
    return tra;
}

/**
 * @brief Calcula e retorna a multiplicação entre duas matrizes
 * Os callbacks retornam um resultado alocado dinamicamente e transferem
 * sua posse à matriz. Cada resultado deve conter pelo menos o número de
 * bytes de um elemento da matriz de saída.
 *
 * @param mat1 - A primeira matriz da multiplicação
 * @param mat2 - A segunda matriz da multiplicação
 * @param numByteTarget - Número de bytes do elemento resultante
 * @param multi_elem - Ponteiro para função (callback) que realiza a multiplicação entre dois elementos do tipo de dados contido na matriz
 * @param soma_elem - Ponteiro para função (callback) que realiza a soma entre dois elementos do tipo de dados contido na matriz
 *
 * @return Ponteiro para uma nova matriz, igual a multiplicação entre mat1 e mat2.
 */
tMatrizGenerica *MultiplicaMatrizes(tMatrizGenerica *mat1, tMatrizGenerica *mat2, int numByteTarget, void *(*multi_elem)(void *, void *), void *(*soma_elem)(void *, void *))
{
    if (!mat1 || !mat2 || !multi_elem || !soma_elem ||
        mat1->colunas != mat2->linhas)
    {
        return NULL;
    }
    tMatrizGenerica *m = CriaMatrizGenerica(mat1->linhas, mat2->colunas, numByteTarget);
    if (!m)
        return NULL;

    for (int i = 0; i < mat1->linhas; i++)
    {
        for (int j = 0; j < mat2->colunas; j++)
        {
            void *produto = multi_elem(mat1->data[i][0], mat2->data[0][j]);
            if (!produto)
                goto falha;
            AtribuiElementoMatrizGenerica(m, i, j, produto);
            free(produto);

            for (int k = 1; k < mat1->colunas; k++)
            {
                produto = multi_elem(mat1->data[i][k], mat2->data[k][j]);
                if (!produto)
                    goto falha;

                void *soma = soma_elem(m->data[i][j], produto);

                free(produto);
                if (!soma)
                    goto falha;
                AtribuiElementoMatrizGenerica(m, i, j, soma);
                free(soma);
            }
        }
    }
    return m;

falha:
    DestroiMatrizGenerica(m);
    return NULL;
}

/**
 * @brief Converte o tipo da matriz
 * Os callbacks retornam um resultado alocado dinamicamente e transferem
 * sua posse à matriz. Cada resultado deve conter pelo menos o número de
 * bytes de um elemento da matriz de saída.
 *
 * @param mat - A matriz que queremos converter para o novo tipo
 * @param novoNumByteElem - Número de bytes do novo tipo da matriz
 * @param converte_elem - Ponteiro para função que tem a capacidade de converter o elemento do tipo original para o novo tipo
 *
 * @return Ponteiro para uma nova matriz, no novo formato
 */
tMatrizGenerica *ConverteTipoMatriz(tMatrizGenerica *mat2, int novoNumByteElem, void *(*converte_elem)(void *))
{
    if (!mat2 || !converte_elem)
        return NULL;

    tMatrizGenerica *matrix = CriaMatrizGenerica(mat2->linhas, mat2->colunas, novoNumByteElem);
    if (!matrix)
        return NULL;

    for (int i = 0; i < mat2->linhas; i++)
    {
        for (int j = 0; j < mat2->colunas; j++)
        {
            void *convertido = converte_elem(mat2->data[i][j]);
            if (!convertido)
            {
                DestroiMatrizGenerica(matrix);
                return NULL;
            }
            AtribuiElementoMatrizGenerica(matrix, i, j, convertido);
            free(convertido);
        }
    }

    return matrix;
}
