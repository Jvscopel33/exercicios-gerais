#include <stdio.h>
#include "loja.h"
#include "vendedor.h"

int main()
{
    int qtdLoja;
    int cmd;
    int qtdCad = 0;
    scanf(" %d\n", &qtdLoja);
    tLoja loja[qtdLoja];
    while (1)
    {
        scanf(" %d\n", &cmd);
        if (cmd == 0)
        {
            return 0;
        }
        else if (cmd == 1)
        {
            int id;
            float alu;
            scanf(" %d %f\n", &id, &alu);
            loja[qtdCad] = AbreLoja(id, alu);
            qtdCad++;
        }
        else if (cmd == 2)
        {
            char nome[50];
            float sal;
            float perCom;
            int id;
            tVendedor v;
            scanf(" %s %f %f\n", nome, &sal, &perCom);
            v = RegistraVendedor(nome, sal, perCom);
            scanf(" %d", &id);
            for (int i = 0; i < qtdCad; i++)
            {
                if (VerificaIdLoja(loja[i], id))
                {
                    loja[i] = ContrataVendedor(loja[i], v);
                }
            }
        }
        else if (cmd == 3)
        {
            int id;
            char nome[50];
            float value;
            scanf(" %d %s %f\n", &id, nome, &value);
            for (int i = 0; i < qtdCad; i++)
            {
                if (VerificaIdLoja(loja[i], id))
                {
                    loja[i] = RegistraVenda(loja[i], nome, value);
                }
            }
        }
        else if (cmd == 4)
        {
            for (int i = 0; i < qtdCad; i++)
            {
                loja[i] = CalculaLucro(loja[i]);
            }
            for (int i = 0; i < qtdCad; i++)
            {
                ImprimeRelatorioLoja(loja[i]);
            }
        }
    }
    return 0;
}