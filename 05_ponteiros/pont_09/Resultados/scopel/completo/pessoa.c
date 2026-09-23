#include <stdio.h>
#include "pessoa.h"
// typedef struct Pessoa tPessoa;

// struct Pessoa{
//     char nome[100];
//     tPessoa *pai;
//     tPessoa *mae;
// };

/**
 * @brief Cria uma nova pessoa com nome vazio (primeiro caractere igual a '\0') e inicializa os ponteiros para pai e mae com NULL.
 *
 * @return Uma nova pessoa e sem pais.
 */
tPessoa CriaPessoa()
{
    tPessoa p;
    p.nome[0] = '\0';
    p.pai = NULL;
    p.mae = NULL;
    return p;
}

/**
 * @brief Lê os dados de uma pessoa.
 *
 * @param pessoa Ponteiro para a pessoa a ser lida.
 */

void LePessoa(tPessoa *pessoa)
{
    scanf(" %[^\n]\n", pessoa->nome);
}

/**
 * @brief Verifica se uma pessoa tem pai e/ou mae associado(s).
 * Ou seja, verifica pelo menos um dos ponteiros pai e mae é diferente de NULL.
 *
 * @param pessoa Ponteiro para a pessoa a ser verificada.
 *
 * @return 1 se a pessoa tiver pai e/ou mae associado(s) e 0 caso contrário.
 */
int VerificaSeTemPaisPessoa(tPessoa *pessoa)
{
    if (pessoa->pai != NULL || pessoa->mae != NULL)
    {
        return 1;
    }
    return 0;
}

/**
 * @brief Imprime os dados de uma pessoa caso tenha pai e/ou mae associado(s).
 * Dica: use a função VerificaSeTemPaisPessoa para verificar se a pessoa tem pai e/ou mae associado(s).
 * Alem disso, imprimir o nome do irmao caso exista.
 *
 * @param pessoa Ponteiro para a pessoa a ser impressa.
 */
void ImprimePessoa(tPessoa *pessoa)
{

    if (VerificaSeTemPaisPessoa(pessoa))
    {
        printf("NOME COMPLETO: %s\n", pessoa->nome);
        if (pessoa->pai != NULL)
        {
            printf("PAI: %s\n", pessoa->pai->nome);
        }
        else
        {
            printf("PAI: NAO INFORMADO\n");
        }
        if (pessoa->mae != NULL)
        {
            printf("MAE: %s\n", pessoa->mae->nome);
        }
        else
        {
            printf("MAE: NAO INFORMADO\n");
        }
    }
}

/**
 * @brief Le as associciacoes da entrada padrao e altera as pessoas de forma a representar as associacoes lidas
 *
 * @param pessoas Ponteiro para a lista de pessoas a serem associadas.
 */
void AssociaFamiliasGruposPessoas(tPessoa *pessoas)
{
    int n;
    int idM;
    int idP;
    int idF;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        while (scanf(" %d", &idM) != 1)
        {
            getchar();
        }

        while (scanf(" %d", &idP) != 1)
        {
            getchar();
        }

        while (scanf(" %d", &idF) != 1)
        {
            getchar();
        }

        if (idM != -1)
        {
            pessoas[idF].mae = &pessoas[idM];
        }
        else
        {
            pessoas[idF].mae = NULL;
        }
        if (idP != -1)
        {
            pessoas[idF].pai = &pessoas[idP];
        }
        else
        {
            pessoas[idF].pai = NULL;
        }
    }
}
