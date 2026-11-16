#include <stdio.h>
#include <stdlib.h>
#include "pacote.h"

struct pacote
{
    void **data;
    int numElem;
    int soma;
    Type type;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar um pacote a ser transmitido
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tPacote *CriaPacote(Type type, int numElem)
{
    tPacote *p = (tPacote *)calloc(1, sizeof(tPacote));
    p->numElem = numElem;
    p->type = type;
    p->soma = 0;
    p->data = calloc(p->numElem, sizeof(*p->data));
    size_t tamanho = (type == CHAR) ? sizeof(char) : sizeof(int);
    for (int i = 0; i < p->numElem; i++)
    {
        p->data[i] = malloc(tamanho);
    }
    return p;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param pac - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiPacote(tPacote *pac)
{
    for (int i = 0; i < pac->numElem; i++)
    {
        free(pac->data[i]);
    }
    free(pac->data);
    free(pac);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param pac - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LePacote(tPacote *pac)
{
    if (pac->type == CHAR)
    {
        for (int i = 0; i < pac->numElem; i++)
        {
            scanf(" %c", (char *)pac->data[i]);
        }
    }
    else if (pac->type == INT)
    {
        for (int i = 0; i < pac->numElem; i++)
        {
            scanf(" %d", (int *)pac->data[i]);
        }
    }
}

/**
 * @brief Imprime na tela um pacote que possui um id específico com seu valor calculado
 *
 * @param pac - O vetor genérico que terá seu conteúdo impresso em tela
 */

void ImprimePacote(tPacote *pac)
{
    CalculaSomaVerificacaoPacote(pac);
    printf("%d", pac->soma);

    if (pac->type == CHAR)
    {
        printf(" ");
        for (int i = 0; i < pac->numElem; i++)
        {
            printf("%c", *(char *)pac->data[i]);
        }
        printf("\n");
    }

    else if (pac->type == INT)
    {
        for (int i = 0; i < pac->numElem; i++)
        {
            printf(" %d", *(int *)pac->data[i]);
        }
        printf("\n");
    }
}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote *pac)
{
    pac->soma = 0;

    if (pac->type == CHAR)
    {
        for (int i = 0; i < pac->numElem; i++)
        {
            pac->soma += *(char *)pac->data[i];
        }
    }
    else if (pac->type == INT)
    {
        for (int i = 0; i < pac->numElem; i++)
        {
            pac->soma += *(int *)pac->data[i];
        }
    }
}
