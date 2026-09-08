#include <stdio.h>
#include <string.h>
#include "paciente.h"
#include "data.h"
#include "lesao.h"

#define MAX_PACIENTE 100

int main()
{
    char cmd;
    int mediaIdade = 0;
    Paciente p[MAX_PACIENTE];
    Data dataBase;
    int totalLesao = 0;
    int totalCir = 0;
    int qtdpaci = 0;
    dataBase = criaData(12, 9, 2023);
    while (1)
    {
        scanf(" %c\n", &cmd);
        if (cmd == 'P')
        {
            p[qtdpaci] = lerPaciente();
            qtdpaci++;
        }
        else if (cmd == 'L')
        {
            Lesao l;
            l = lerLesao();
            char cmp[MAX_CARTAO_SUS], cmpL[MAX_CARTAO_LES];
            for (int i = 0; i < qtdpaci; i++)
            {
                getCartaoSusPaciente(p[i], cmp);
                getCartaoSusLesao(l, cmpL);
                if (!strcmp(cmp, cmpL))
                {
                    p[i] = vinculaLesaoPaciente(p[i], l);
                }
            }
        }
        else if (cmd == 'F')
        {
            break;
        }
    }
    for (int i = 0; i < qtdpaci; i++)
    {
        mediaIdade += calculaIdadePaciente(p[i], dataBase);
        totalLesao += getNumLesoesPaciente(p[i]);
        totalCir += qtdLesoesCirurgicasPaciente(p[i]);
    }
    if (qtdpaci > 0)
    {
        mediaIdade = mediaIdade / qtdpaci;
    }
    printf("TOTAL PACIENTES: %d\n", qtdpaci);
    if (qtdpaci > 0)
    {
        printf("MEDIA IDADE (ANOS): %d\n", mediaIdade);
    }
    else
    {
        printf("MEDIA IDADE (ANOS): -\n");
    }
    printf("TOTAL LESOES: %d\n", totalLesao);
    printf("TOTAL CIRURGIAS: %d\n", totalCir);
    printf("LISTA DE PACIENTES:\n");
    for (int i = 0; i < qtdpaci; i++)
    {
        imprimePaciente(p[i]);
    }
    return 0;
}