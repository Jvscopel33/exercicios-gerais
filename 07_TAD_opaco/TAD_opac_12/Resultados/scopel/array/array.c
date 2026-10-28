#include <stdio.h>
#include <stdlib.h>
#include "array.h"

struct Array
{
    int *vetor;
    int qtdElementos;
};

/**
 * @brief Inicializa um novo array, apontando data para NULL e tamanho para 0.
 * @return Ponteiro para a estrutura Array criada ou encerra caso não seja possível alocar memória.
 */
Array *CriarArray()
{
    Array *a = calloc(1, sizeof(Array));
    a->qtdElementos = 0;
    a->vetor = NULL;
    return a;
}

/**
 * @brief Libera a memória alocada para o array.
 * @param array Ponteiro para a estrutura Array a ser destruída.
 */
void DestruirArray(Array *array)
{
    free(array->vetor);
    free(array);
}

/**
 * @brief Lê os elementos do array a partir da entrada padrão e aloca memória para eles.
 * @details A leitura é feita até encontrar um ponto final (.) na entrada.
 * @param array Ponteiro para a estrutura Array a ser preenchida.
 */
void LerArray(Array *array)
{
    int elemento;
    while (scanf(" %d", &elemento) == 1)
    {
        array->vetor = realloc(array->vetor, (array->qtdElementos + 1) * sizeof(int));
        array->vetor[array->qtdElementos] = elemento;
        array->qtdElementos++;
    }
    getchar();
}

/**
 * @brief Ordena os elementos do array em ordem crescente.
 * @param array Ponteiro para a estrutura Array a ser ordenada.
 */
void OrdenarArray(Array *array)
{
    for (int i = 0; i < array->qtdElementos; i++)
    {
        for (int j = 0; j < array->qtdElementos - 1 - i; j++)
        {
            int temp;
            if (array->vetor[j] > array->vetor[j + 1])
            {
                temp = array->vetor[j + 1];
                array->vetor[j + 1] = array->vetor[j];
                array->vetor[j] = temp;
            }
        }
    }
}

/**
 * @brief Realiza uma busca binária no array pelo elemento especificado.
 * @param array Ponteiro para a estrutura Array a ser buscada.
 * @param elementoBuscado Elemento a ser buscado no array.
 * @return Índice do elemento buscado no array, ou -1 caso não seja encontrado.
 */
int BuscaBinariaArray(Array *array, int elementoBuscado)
{
    int inicio = 0;
    int fim = array->qtdElementos - 1;
    int metade = 0;
    while (inicio <= fim)
    {
        metade = inicio + (fim - inicio) / 2;
        if (array->vetor[metade] == elementoBuscado)
        {
            return metade;
        }
        if (array->vetor[metade] > elementoBuscado)
        {
            fim = metade - 1;
        }
        if (array->vetor[metade] < elementoBuscado)
        {
            inicio = metade + 1;
        }
    }
    return -1;
}
