#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include "conta.h"
#include "banco.h"
struct Banco
{
    tConta **conta;
    int qtdContasAlocadas;
    int qtdContasAbertas;
};

/**
 * @brief Cria um novo banco, com 5 contas alocadas e nenhuma conta aberta.
 * Se não for possível alocar memória, o programa é encerrado.
 *
 * @return Um ponteiro para o novo banco criado.
 */
tBanco *CriaBanco()
{
    tBanco *b = (tBanco *)calloc(1, sizeof(tBanco));
    b->conta = (tConta **)calloc(5, sizeof(tConta *));
    b->qtdContasAlocadas = 5;
    b->qtdContasAbertas = 0;
    return b;
}

/**
 * @brief Desaloca a memória de um banco e de todas as suas contas.
 *
 * @param banco Ponteiro para o banco a ser destruído.
 */

void DestroiBanco(tBanco *banco)
{
    for (int i = 0; i < banco->qtdContasAbertas; i++)
    {
        DestroiConta(banco->conta[i]);
    }
    free(banco->conta);
    free(banco);
}

/**
 * @brief Abre uma nova conta no banco e a adiciona ao vetor de contas.
 *
 * @param banco Ponteiro para o banco onde a conta será aberta.
 */
void AbreContaBanco(tBanco *banco)
{
    if (banco->qtdContasAlocadas < banco->qtdContasAbertas)
    {
        banco->conta[banco->qtdContasAbertas] = CriaConta();
        LeConta(banco->conta[banco->qtdContasAbertas]);
        banco->qtdContasAbertas++;
    }
    else
    {
        banco->conta = (tConta **)realloc(banco->conta, (banco->qtdContasAlocadas + 1) * sizeof(tConta *));
        banco->conta[banco->qtdContasAbertas] = CriaConta();
        LeConta(banco->conta[banco->qtdContasAbertas]);
        banco->qtdContasAbertas++;
        banco->qtdContasAlocadas++;
    }
}

/**
 * @brief Realiza um saque em uma conta do banco se ela existir e tiver saldo suficiente.
 * Nessa função é necessário ler o número da conta e o valor do saque.
 *
 * @param banco Ponteiro para o banco onde a conta será sacada.
 */

void SaqueContaBanco(tBanco *banco)
{
    int id;
    float valor;
    scanf(" %d %f\n", &id, &valor);
    for (int i = 0; i < banco->qtdContasAbertas; i++)
    {
        if (VerificaConta(banco->conta[i], id))
        {
            SaqueConta(banco->conta[i], valor);
            break;
        }
    }
}

/**
 * @brief Realiza um depósito em uma conta do banco se ela existir.
 * Nessa função é necessário ler o número da conta e o valor do depósito.
 *
 * @param banco Ponteiro para o banco onde a conta será depositada.
 */
void DepositoContaBanco(tBanco *banco)
{
    int id;
    float valor;
    scanf(" %d %f\n", &id, &valor);
    for (int i = 0; i < banco->qtdContasAbertas; i++)
    {
        if (VerificaConta(banco->conta[i], id))
        {
            DepositoConta(banco->conta[i], valor);
            break;
        }
    }
}

/**
 * @brief Realiza uma transferência entre duas contas do banco se elas existirem e a conta de origem tiver saldo suficiente.
 * Nessa função é necessário ler o número da conta de origem, o número da conta de destino e o valor da transferência.
 *
 * @param banco Ponteiro para o banco onde as contas estão.
 */
void TransferenciaContaBanco(tBanco *banco)
{
    tConta *origem = NULL;
    tConta *destino = NULL;
    int idOrig, idDest;
    float valor;
    scanf(" %d %d %f\n", &idDest, &idOrig, &valor);
    for (int i = 0; i < banco->qtdContasAbertas; i++)
    {
        if (VerificaConta(banco->conta[i], idOrig))
        {
            origem = banco->conta[i];
        }
    }
    for (int i = 0; i < banco->qtdContasAbertas; i++)
    {
        if (VerificaConta(banco->conta[i], idDest))
        {
            destino = banco->conta[i];
        }
    }
    TransferenciaConta(destino, origem, valor);
}

/**
 * @brief Imprime o relatório do banco, com todas as contas e seus respectivos dados.
 *
 * @param banco Ponteiro para o banco a ser impresso.
 */
void ImprimeRelatorioBanco(tBanco *banco)
{
    printf("===| Imprimindo Relatorio |===\n");
    for (int i = 0; i < banco->qtdContasAbertas; i++)
    {
        ImprimeConta(banco->conta[i]);
    }
}
