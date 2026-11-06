#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "movel.h"

#define MAX_NOME 50
/**
 * @brief Estrutura representando um Movel.
 */
struct Movel
{
    char nome[50];
};

/**
 * @brief Cria um novo Movel.
 * @param nome O nome do Movel.
 * @return Um ponteiro para o novo Movel.
 */

tMovel *CriaMovel(char *nome)
{
    tMovel *m = (tMovel *)calloc(1, sizeof(tMovel));
    strcpy(m->nome, nome);
    return m;
}

/**
 * @brief Destroi um Movel.
 * @param m O Movel a ser destruído.
 */
void DestroiMovel(tMovel *m)
{
    free(m);
}

/**
 * @brief Lê um Movel.
 * @return O Movel lido.
 */
tMovel *LeMovel()
{
    tMovel m;
    scanf(" %s\n", m.nome);
    return CriaMovel(m.nome);
}

/**
 * @brief Imprime o nome do movel.
 * @param m O Movel a ser impresso.
 */
void ImprimeMovel(tMovel *m)
{
    printf("%s\n", m->nome);
}

// _MOVEL_H_