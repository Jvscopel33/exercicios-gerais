#include <stdio.h>
#include "usuario.h"
#include "conta.h"
#include <stdlib.h>
int main()
{
    int n;
    int aux = 0;
    scanf(" %d\n", &n);
    tConta c[n];
    tUsuario u[n];
    int cmd;
    while (1)
    {
        scanf(" %d\n", &cmd);
        if (cmd == 0)
        {
            exit(1);
        }
        else if (cmd == 2)
        {
            int numac;
            float value;
            scanf(" %d %f", &numac, &value);
            for (int i = 0; i < n; i++)
            {
                if (VerificaConta(c[i], numac))
                {
                    c[i] = DepositoConta(c[i], value);
                }
            }
        }
        else if (cmd == 1)
        {
            int numac;
            float value;
            scanf(" %d %f", &numac, &value);
            for (int i = 0; i < n; i++)
            {
                if (VerificaConta(c[i], numac))
                {
                    c[i] = SaqueConta(c[i], value);
                }
            }
        }
        else if (cmd == 3)
        {
            if (aux < n)
            {
                char nome[50];
                char cpf[15];
                int numac;
                scanf(" %s %s %d\n", nome, cpf, &numac);
                u[aux] = CriaUsuario(nome, cpf);
                c[aux] = CriaConta(numac, u[aux]);
                aux++;
            }
        }
        else if (cmd == 4)
        {
            printf("===| Imprimindo Relatorio |===\n");
            for (int i = 0; i < n; i++)
            {
                ImprimeConta(c[i]);
                printf("\n");
            }
        }
    }
    return 0;
}