#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cidade.h"
#include "missil.h"
#include "defesa.h"

#define MAX_NOME 10 /**< Tamanho máximo do nome da cidade. */

#define QTD_DEF 10 /**< Quantidade máxima de defesas que uma cidade pode ter. */
#define QTD_MIS 10 /**< Quantidade máxima de mísseis que uma cidade pode ter. */

#define ENCERRAR 'F' /**< Caractere que indica o fim da entrada. */
#define MISSIL 'M'   /**< Caractere que indica um míssil. */
#define DEFESA 'D'   /**< Caractere que indica uma defesa. */

/**
 * @brief Estrutura que representa uma cidade.
 *
 * A estrutura tCidade contém o nome da cidade, a quantidade de mísseis e defesas, e as listas de mísseis e defesas.
 *
 */
struct cidade
{
    float x, y;
    char nome[MAX_NOME];
    tMissil missil[QTD_DEF];
    tDefesa defesa[QTD_DEF];
    int qtdDefesa;
    int qtdMisseis;
    float danoFeito, danoRecebido;
};

/**
 * @brief Cria uma nova cidade.
 *
 * @return tCidade Ponteiro para a cidade criada.
 */

tCidade CriaCidade()
{
    tCidade c = (tCidade)calloc(1, sizeof(struct cidade));
    c->x = 0;
    c->y = 0;
    c->danoRecebido = 0;
    c->danoFeito = 0;
    c->qtdDefesa = 0;
    c->qtdMisseis = 0;
    return c;
}

/**
 * @brief Lê a entrada do usuário e preenche a cidade com as informações lidas.
 *
 * @param cidade Ponteiro para a cidade que será preenchida.
 * @return tCidade Ponteiro para a cidade preenchida.
 */

tCidade LeEntrada(tCidade cidade)
{
    char tipo;
    scanf(" %s %f %f\n", cidade->nome, &cidade->x, &cidade->y);
    while (1)
    {
        scanf(" %c", &tipo);
        if (tipo == 'F')
        {
            break;
        }
        if (tipo == 'D')
        {
            cidade->missil[cidade->qtdMisseis] = LeMissil();
            cidade->qtdMisseis++;
        }
        else if (tipo == 'M')
        {
            cidade->defesa[cidade->qtdDefesa] = LeDefesa();
            cidade->qtdDefesa++;
        }
    }
    return cidade;
}

/**
 * @brief Imprime as informações da cidade.
 *
 * @param cidade Ponteiro para a cidade que será impressa.
 */

void ImprimeCidade(tCidade cidade)
{
}

/**
 * @brief Libera a memória alocada para a cidade.
 *
 * @param cidade Ponteiro para a cidade que terá a memória liberada.
 */
void LiberaCidade(tCidade cidade)
{
    for (int i = 0; i < cidade->qtdDefesa; i++)
    {
        LiberaMissil(cidade->missil[i]);
    }
    for (int i = 0; i < cidade->qtdMisseis; i++)
    {
        LiberaDefesa(cidade->defesa[i]);
    }
    free(cidade);
}

/**
 * @brief Processa os ataques na cidade.
 *
 * @param cidade Ponteiro para a cidade que será atacada.
 */

void ProcessaAtaques(tCidade cidade)
{
    for (int i = 0; i < cidade->qtdMisseis; i++)
    {
        cidade->danoRecebido = GetMissilPoder(cidade->missil[i]);
        for (int j = 0; j < cidade->qtdDefesa; j++)
        {
            if (VerificaSeDentroArea(cidade->defesa[j], GetMissilX(cidade->missil[i]), GetMissilY(cidade->missil[i])))
            {
                if (PodeDefender(cidade->defesa[j]))
                {
                    if (GetDefesaPoder(cidade->defesa[i]) > cidade->danoRecebido)
                    {
                        cidade->danoFeito += GetMissilPoder(cidade->missil[i]);
                    }
                }
            }
        }
    }
}

/**
 * @brief Imprime os dados finais da cidade.
 *
 * @param cidade Ponteiro para a cidade que terá os dados impressos.
 */
void ImprimeDados(tCidade cidade);
