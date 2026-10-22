#include <stdio.h>
#include <stdlib.h>
#include "agencia.h"
#include "conta.h"
#include "operacao.h"

struct Agencia
{
    tConta **contas;
    int qtdContas;
    int qtdContasAlocadas;
    tOperacao **Op;
    int qtdOp;
};

/**
 * @brief Cria uma variável (alocada dinamicamente) do tipo tAgencia. Ponteiros devem ser inicializados com NULL e variáveis numéricas com valor zero.
 *
 * @return A variável do tipo Agencia inicializada.
 */

tAgencia *CriaAgencia()
{
    tAgencia *a = calloc(1, sizeof(tAgencia));
    a->contas = NULL;
    a->qtdContas = 0;
    a->qtdOp = 0;
    a->Op = NULL;
    a->qtdContasAlocadas = 0;
    return a;
}

/**
 * @brief Libera toda a memória alocada para armazenar dados de uma agencia.
 *
 * @param A variável do tipo Agencia que será apagada.
 */
void DestroiAgencia(tAgencia *agencia)
{
    for (int i = 0; i < agencia->qtdContas; i++)
    {
        DestroiConta(agencia->contas[i]);
    }
    free(agencia->contas);
    for (int i = 0; i < agencia->qtdOp; i++)
    {
        DestroiOperacao(agencia->Op[i]);
    }
    free(agencia->Op);
    free(agencia);
}

/**
 * @brief Le as informações de uma agencia - contas e operações, no formato especificado no roteiro
 *
 * @param agencia - A variável do tipo agencia que salvará os dados lidos
 */
void LeOperacoes(tAgencia *agencia)
{
    int id;
    int OpAlocadas = 0;
    int numAc;
    float valor;
    scanf(" %d\n", &agencia->qtdContas);
    while (1)
    {
        if (agencia->qtdContasAlocadas == agencia->qtdContas)
        {
            break;
        }
        scanf(" %d\n", &id);
        if (id > 0)
        {
            if (BuscaContaPorId(agencia, id) == NULL)
            {
                agencia->contas = realloc(agencia->contas, (agencia->qtdContasAlocadas + 1) * sizeof(tConta *));
                agencia->contas[agencia->qtdContasAlocadas] = CriaConta(id);
                agencia->qtdContasAlocadas++;
            }
            else
            {
                printf("\nEste id ja esta cadastrado na agencia. Digite um id diferente!");
            }
        }
        else
        {
            printf("\nDigite um id valido para a conta a ser cadastrada!");
            continue;
        }
    }
    scanf(" %d\n", &agencia->qtdOp);
    while (1)
    {
        if (OpAlocadas == agencia->qtdOp)
        {
            break;
        }
        else
        {
            scanf(" %d %f\n", &numAc, &valor);
            if (BuscaContaPorId(agencia, numAc) == NULL)
            {
                printf("\nConta Invalida! Repita a operacao, mas com uma conta valida!");
                continue;
            }
            for (int i = 0; i < agencia->qtdContasAlocadas; i++)
            {

                if (ConfereIdConta(agencia->contas[i], numAc))
                {
                    agencia->Op = realloc(agencia->Op, (OpAlocadas + 1) * sizeof(tOperacao *));
                    agencia->Op[OpAlocadas] = CriaOperacao(agencia->contas[i], valor);
                    AlteraSaldoConta(agencia->contas[i], valor);
                    OpAlocadas++;
                }
            }
        }
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param agencia - A agencia na qual queremos buscar a conta com o id específico
 * @param id - o ID da conta que queremos buscar
 *conferido
 * @return A conta, caso exista, e NULL, caso contrário
 */
tConta *BuscaContaPorId(tAgencia *agencia, int id)
{
    if (agencia == NULL || agencia->contas == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < agencia->qtdContasAlocadas; i++)
    {
        if (ConfereIdConta(agencia->contas[i], id))
        {
            return agencia->contas[i];
        }
    }
    return NULL;
}

/**
 * @brief Função que imprime em tela as operações suspeitas de uma agência
 *
 * @param agencia A Agência na qual as operações suspeitas serão impressas em tela.
 */
void ImprimeOperacoesSuspeitas(tAgencia *agencia)
{
    printf("\nA lista de operações suspeitas:");
    for (int i = 0; i < agencia->qtdOp; i++)
    {
        if (ConsultaValorOperacao(agencia->Op[i]) > 20000.00 || ConsultaValorOperacao(agencia->Op[i]) < -20000.00)
        {
            ImprimeOperacao(agencia->Op[i]);
        }
    }
}

/**
 * @brief Função que imprime em tela os dois correntistas com maior saldo
 *
 * @param agencia A Agência na qual os dois correntistas com maior saldo impressos em tela.
 */
void ImprimeDoisCorrentistasComMaiorSaldo(tAgencia *agencia)
{
    int maiorSaldo = -1;
    int segundoMaiorSaldo = -1;
    float maiorValor = -1;
    for (int i = 0; i < agencia->qtdContasAlocadas; i++)
    {
        if (RetornaSaldoConta(agencia->contas[i]) > maiorValor)
        {
            maiorSaldo = RetornaIdConta(agencia->contas[i]);
            maiorValor = RetornaSaldoConta(agencia->contas[i]);
        }
    }
    maiorValor = -1;
    for (int i = 0; i < agencia->qtdContasAlocadas; i++)
    {
        if ((RetornaSaldoConta(agencia->contas[i]) > maiorValor) && (RetornaIdConta(agencia->contas[i]) != maiorSaldo))
        {
            segundoMaiorSaldo = RetornaIdConta(agencia->contas[i]);
            maiorValor = RetornaSaldoConta(agencia->contas[i]);
        }
    }
    printf("\nOs dois correntistas com maior saldo são:");
    printf("\nId: %d, Saldo: %.2f\n", RetornaIdConta(BuscaContaPorId(agencia, maiorSaldo)), RetornaSaldoConta(BuscaContaPorId(agencia, maiorSaldo)));
    printf("Id: %d, Saldo: %.2f\n", RetornaIdConta(BuscaContaPorId(agencia, segundoMaiorSaldo)), RetornaSaldoConta(BuscaContaPorId(agencia, segundoMaiorSaldo)));
}

/**
 * @brief Função que imprime em tela o saldo total da agência
 *
 * @param agencia A Agência na qual o saldo total impresso em tela.
 */
void ImprimeSaldoTotal(tAgencia *agencia)
{
    float soma = 0;
    for (int i = 0; i < agencia->qtdContasAlocadas; i++)
    {
        soma += RetornaSaldoConta(agencia->contas[i]);
    }
    printf("O saldo total da agencia eh: %.2f\n", soma);
}
