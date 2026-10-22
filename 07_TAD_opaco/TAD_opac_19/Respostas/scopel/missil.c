#include <stdio.h>
#include <stdlib.h>
#include "missil.h"

#define MAX_TAM 100 /**< Tamanho máximo do nome do míssil. */

/**
 * @brief Estrutura que representa um míssil.
 *
 * A estrutura tMissil contém o nome do míssil, as coordenadas x e y, e o poder de ataque.
 *
 */
struct missil
{
    float x, y;
    float power;
    char nome[MAX_TAM];
};

/**
 * @brief Lê a entrada do usuário e cria um novo míssil.
 *
 * @return tMissil Ponteiro para o míssil criado.
 */
tMissil LeMissil()
{
    tMissil m = calloc(1, sizeof(struct missil));
    scanf(" %s", m->nome);
    scanf(" %f", &m->x);
    scanf(" %f", &m->y);
    scanf(" %f\n", &m->power);
    return m;
}

/**
 * @brief Imprime as informações do míssil.
 *
 * @param missil Ponteiro para o míssil que será impresso.
 */
void ImprimeMissil(tMissil missil)
{
    printf("M-%s: %.2f\n", missil->nome, missil->power);
}

/**
 * @brief Libera a memória alocada para o míssil.
 *
 * @param missil Ponteiro para o míssil que terá a memória liberada.
 */
void LiberaMissil(tMissil missil)
{
    free(missil);
}

/**
 * @brief Obtém a coordenada y do míssil.
 *
 * @param missil Ponteiro para o míssil que terá a coordenada y obtida.
 * @return float Coordenada y do míssil.
 */
float GetMissilY(tMissil missil)
{
    return missil->y;
}

/**
 * @brief Obtém a coordenada x do míssil.
 *
 * @param missil Ponteiro para o míssil que terá a coordenada x obtida.
 * @return float Coordenada x do míssil.
 */
float GetMissilX(tMissil missil)
{
    return missil->x;
}

/**
 * @brief Obtém o poder de ataque do míssil.
 *
 * @param missil Ponteiro para o míssil que terá o poder de ataque obtido.
 * @return float Poder de ataque do míssil.
 */
float GetMissilPoder(tMissil missil)
{
    return missil->power;
}

/**
 * @brief Reduz o poder de ataque do míssil.
 *
 * @param missil Ponteiro para o míssil que terá o poder de ataque reduzido.
 * @param valor Valor a ser subtraído do poder de ataque do míssil.
 */
void ReduzPoder(tMissil missil, float valor)
{
    if ((missil->power - valor) >= 0)
    {
        missil->power = missil->power - valor;
    }
    else
    {
        missil->power = 0;
    }
}
