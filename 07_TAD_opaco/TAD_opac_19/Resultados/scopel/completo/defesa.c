#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "defesa.h"
#include "missil.h"

#define QUADRADO 'Q' /**< Caractere que indica uma defesa do tipo quadrado. */
#define CIRCULO 'C'  /**< Caractere que indica uma defesa do tipo círculo. */
#define MAX_TAM 100  /**< Tamanho máximo do nome da defesa. */

/**
 * @brief Estrutura que representa uma defesa.
 *
 * A estrutura tDefesa contém o tipo da defesa, as coordenadas do centro, o tamanho e o poder de defesa.
 *
 */
struct defesa
{
    float defendPower;
    char nome[MAX_TAM];
    float x, y;
    char tipoDefesa;
    float areaDefesa;
    int qtdMisseisDefesa;
};

/**
 * @brief Lê a entrada do usuário e cria uma nova defesa.
 *
 * @return tDefesa Ponteiro para a defesa criada.
 */
tDefesa LeDefesa()
{
    tDefesa d = (tDefesa)calloc(1, sizeof(struct defesa));
    scanf(" %s %f %f %c %f %f %d", d->nome, &d->x, &d->y, &d->tipoDefesa, &d->areaDefesa, &d->defendPower, &d->qtdMisseisDefesa);
    return d;
}

/**
 * @brief Imprime as informações da defesa.
 *
 * @param defesa Ponteiro para a defesa que será impressa.
 */
void ImprimeDefesa(tDefesa defesa)
{
    printf("D-%s: %d\n", defesa->nome, defesa->qtdMisseisDefesa);
}

/**
 * @brief Libera a memória alocada para a defesa.
 *
 * @param defesa Ponteiro para a defesa que terá a memória liberada.
 */
void LiberaDefesa(tDefesa defesa)
{
    free(defesa);
}

/**
 * @brief Verifica se um ponto está dentro da área de defesa.
 *
 * @param defesa Ponteiro para a defesa que será verificada.
 * @param x Coordenada x do ponto.
 * @param y Coordenada y do ponto.
 * @return int 1 se o ponto está dentro da área de defesa, 0 caso contrário.
 */

int VerificaSeDentroArea(tDefesa defesa, float x, float y)
{
    float dist = 0;
    if (defesa->tipoDefesa == CIRCULO)
    {
        dist = sqrt((pow((defesa->x - x), 2) + pow((defesa->y - y), 2)));
        if (dist < defesa->areaDefesa)
        {
            return 1;
        }
        return 0;
    }
    if (defesa->tipoDefesa == QUADRADO)
    {
        dist = (defesa->areaDefesa * 2) / sqrt(2);
        if (fabs(defesa->x - x) > dist || fabs(defesa->y - y) > dist)
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Usa a defesa, diminuindo seu poder de defesa.
 *
 * @param defesa Ponteiro para a defesa que será usada.
 */

void UsaDefesa(tDefesa defesa)
{
    defesa->qtdMisseisDefesa -= 1;
}

/**
 * @brief Obtém o poder de defesa da defesa.
 *
 * @param defesa Ponteiro para a defesa que terá o poder de defesa obtido.
 * @return float Poder de defesa da defesa.
 */
float GetDefesaPoder(tDefesa defesa)
{
    return defesa->defendPower;
}

/**
 * @brief Verifica se a defesa pode defender.
 *
 * @param defesa Ponteiro para a defesa que será verificada.
 * @return int 1 se a defesa pode defender, 0 caso contrário.
 */
int PodeDefender(tDefesa defesa)
{
    if (defesa->qtdMisseisDefesa > 0)
    {
        return 1;
    }
    return 0;
}
