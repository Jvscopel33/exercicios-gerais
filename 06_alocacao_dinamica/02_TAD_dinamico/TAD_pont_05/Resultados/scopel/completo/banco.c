#include <stdio.h>
#include <stdlib.h>
#include "banco.h"
#include "conta.h"

// typedef struct Banco {
//     tConta **contas;
//     int qtdContas;
//     int contasAlocadas;
// } tBanco;

/**
 * @brief Cria um novo banco, com 5 contas alocadas e nenhuma conta aberta.
 * Se não for possível alocar memória, o programa é encerrado.
 *
 * @return Um ponteiro para o novo banco criado.
 */
tBanco *CriaBanco()
{
    tBanco *b = (tBanco *)calloc(1, sizeof(tBanco));
    if (b == NULL)
    {
        printf("DEU RUIM NA ALOCACAO DO BANCO\n");
        exit(1);
    }
    b->contas = (tConta **)calloc(5, sizeof(tConta *));
    if (b->contas == NULL)
    {
        printf("DEU RUIM NA ALOCACAO DAS CONTAS\n");
        free(b);
        exit(1);
    }
    b->contasAlocadas = 5;
    b->qtdContas = 0;
    return b;
}

/**
 * @brief Desaloca a memória de um banco e de todas as suas contas.
 *
 * @param banco Ponteiro para o banco a ser destruído.
 */
void DestroiBanco(tBanco *banco)
{
    for (int i = 0; i < banco->qtdContas; i++)
    {
        DestroiConta(banco->contas[i]);
    }
    free(banco->contas);
    free(banco);
}

/**
 * @brief Abre uma nova conta no banco e a adiciona ao vetor de contas.
 *
 * @param banco Ponteiro para o banco onde a conta será aberta.
 */
void AbreContaBanco(tBanco *banco)
{
    if (banco->contasAlocadas > banco->qtdContas)
    {
        banco->contas[banco->qtdContas] = CriaConta();
        LeConta(banco->contas[banco->qtdContas]);
        banco->qtdContas++;
    }
}
/**
 * @brief Realiza um saque em uma conta do banco se ela existir e tiver saldo suficiente.
 *
 * @param banco Ponteiro para o banco onde a conta será sacada.
 */
void SaqueContaBanco(tBanco *banco)
{
    int numeroDaConta;
    float valor;
    scanf(" %d %f\n", &numeroDaConta, &valor);
    for (int i = 0; i < banco->qtdContas; i++)
    {
        if (VerificaConta(banco->contas[i], numeroDaConta))
        {
            SaqueConta(banco->contas[i], valor);
        }
    }
}

/**
 * @brief Realiza um depósito em uma conta do banco se ela existir.
 *
 * @param banco Ponteiro para o banco onde a conta será depositada.
 */
void DepositoContaBanco(tBanco *banco)
{
    int numeroDaConta = 0;
    float valor;
    scanf(" %d %f\n", &numeroDaConta, &valor);
    for (int i = 0; i < banco->qtdContas; i++)
    {
        if (VerificaConta(banco->contas[i], numeroDaConta))
        {
            DepositoConta(banco->contas[i], valor);
        }
    }
}

/**
 * @brief Realiza uma transferência entre duas contas do banco se elas existirem e a conta de origem tiver saldo suficiente.
 *
 * @param banco Ponteiro para o banco onde as contas estão.
 */
void TransferenciaContaBanco(tBanco *banco)
{
    int conta1, conta2;
    int id1 = -1, id2 = -1;
    float valor;
    scanf(" %d %d %f\n", &conta1, &conta2, &valor);
    // ENCONTRAR O INDICE DA PRIMEIRA CONTA
    for (int i = 0; i < banco->qtdContas; i++)
    {
        if (VerificaConta(banco->contas[i], conta1))
        {
            id1 = i;
        }
    }
    // ENCONTRAR O INDICE DA SEGUNDA CONTA
    for (int i = 0; i < banco->qtdContas; i++)
    {
        if (VerificaConta(banco->contas[i], conta2))
        {
            id2 = i;
        }
    }
    if (id1 != -1 && id2 != -1)
    {
        TransferenciaConta(banco->contas[id1], banco->contas[id2], valor);
    }
}

/**
 * @brief Imprime o relatório do banco, com todas as contas e seus respectivos dados.
 *
 * @param banco Ponteiro para o banco a ser impresso.
 */
void ImprimeRelatorioBanco(tBanco *banco)
{
    printf("===| Imprimindo Relatorio |===\n");
    for (int i = 0; i < banco->qtdContas; i++)
    {
        ImprimeConta(banco->contas[i]);
        printf("\n");
    }
}
