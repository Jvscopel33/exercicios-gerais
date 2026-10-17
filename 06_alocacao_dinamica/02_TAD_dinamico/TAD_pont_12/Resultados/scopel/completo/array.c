#include <stdio.h>
#include <stdlib.h>
#include "array.h"

// typedef struct Array {
//     int *data;
//     int tamanho;
// } Array;

/**
 * @brief Inicializa um novo array, apontando data para NULL e tamanho para 0.
 * @return Ponteiro para a estrutura Array criada ou encerra caso não seja possível alocar memória.
 */
Array *CriarArray()
{
    Array *a = (Array *)calloc(1, sizeof(Array));
    a->data = NULL;
    a->tamanho = 0;
    return a;
}

/**
 * @brief Libera a memória alocada para o array.
 * @param array Ponteiro para a estrutura Array a ser destruída.
 */
void DestruirArray(Array *array)
{
    free(array->data);
    free(array);
}

/**
 * @brief Lê os elementos do array a partir da entrada padrão e aloca memória para eles.
 * @details A leitura é feita até encontrar um ponto final (.) na entrada.
 * @param array Ponteiro para a estrutura Array a ser preenchida.
 */
void LerArray(Array *array)
{
    int data;
    while (scanf(" %d", &data) == 1)
    {
        array->data = realloc(array->data, (array->tamanho + 1) * sizeof(int));
        array->data[array->tamanho] = data;
        array->tamanho++;
    }
    getchar();
}

/**
 * @brief Ordena os elementos do array em ordem crescente.
 * @param array Ponteiro para a estrutura Array a ser ordenada.
 */
void OrdenarArray(Array *array)
{
    Array *aux;
    for (int i = 0; i < array->tamanho; i++)
    {

        for (int j = 0; j < array->tamanho - 1 - i; j++)
        {
            if (array->data[j + 1] < array->data[j])
            {
                aux = array->data[j + 1];
                array->data[j + 1] = array->data[j];
                array->data[j] = aux;
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
    int fim = array->tamanho - 1;
    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;
        if (array->data[meio] == elementoBuscado)
        {
            return meio;
        }
        else if (array->data[meio] < elementoBuscado)
        {
            inicio = meio + 1;
        }
        else if (array->data[meio] > elementoBuscado)
        {
            fim = meio - 1;
        }
    }
    return -1;
}
