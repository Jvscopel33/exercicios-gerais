#include <stdio.h>
#include <stdlib.h>
#include "loja.h"
#include "vendedor.h"

int main()
{
    tLoja **Lojas = NULL;
    int qtdLojas = 0;
    int cmd;
    int qtdLojasEsperadas;
    scanf(" %d\n", &qtdLojasEsperadas);
    while (1)
    {
        scanf(" %d\n", &cmd);
        if (cmd == 0)
        {
            break;
        }
        if (cmd == 1)
        {
            int id;
            float aluguel;
            scanf(" %d %f\n", &id, &aluguel);
            Lojas = (tLoja **)realloc(Lojas, (qtdLojas + 1) * sizeof(tLoja *));
            Lojas[qtdLojas] = AbreLoja(id, aluguel);
            qtdLojas++;
        }
        else if (cmd == 2)
        {
            char nome[100];
            float salario, porcentagem_comisao;
            int idLoja;

            scanf(" %s %f %f\n", nome, &salario, &porcentagem_comisao);
            scanf(" %d\n", &idLoja);

            for (int i = 0; i < qtdLojas; i++)
            {
                if (VerificaIdLoja(Lojas[i], idLoja))
                {
                    ContrataVendedor(Lojas[i], RegistraVendedor(nome, salario, porcentagem_comisao));
                }
            }
        }
        else if (cmd == 3)
        {
            int idLoja;
            char nomeV[100];
            float venda;
            scanf(" %d %s %f", &idLoja, nomeV, &venda);
            for (int i = 0; i < qtdLojas; i++)
            {
                if (VerificaIdLoja(Lojas[i], idLoja))
                {
                    RegistraVenda(Lojas[i], nomeV, venda);
                    break;
                }
            }
        }
        else if (cmd == 4)
        {
            for (int i = 0; i < qtdLojas; i++)
            {
                CalculaLucro(Lojas[i]);
                ImprimeRelatorioLoja(Lojas[i]);
            }
        }
    }
    for (int i = 0; i < qtdLojas; i++)
    {
        ApagaLoja(Lojas[i]);
    }
    free(Lojas);
    return 0;
}