#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"
#include "data.h"
#include "lesao.h"

void estatisticas(Paciente **p, int qtdPac);
int calculaMedia(Paciente **p, int qtdPac);
int contabilizaLesoes(Paciente **p, int qtdPac);
int contabilizaCirurgia(Paciente **p, int qtdPac);

int main()
{
    int qtdPac = 0;
    Paciente **p = NULL;
    Lesao *l = NULL;
    char cmd;
    while (1)
    {
        scanf(" %c\n", &cmd);
        if (cmd == 'F')
        {
            break;
        }
        else if (cmd == 'P')
        {
            p = realloc(p, (qtdPac + 1) * sizeof(Paciente *));
            p[qtdPac] = lerPaciente();
            qtdPac++;
        }
        else if (cmd == 'L')
        {
            int add = 0;
            l = lerLesao();
            for (int i = 0; i < qtdPac; i++)
            {
                if (!(strcmp(getCartaoSusLesao(l), getCartaoSusPaciente(p[i]))))
                {
                    adicionaLesaoPaciente(p[i], l);
                    add++;
                    break;
                }
            }
            if (!add)
            {
                liberaLesao(l);
            }
        }
    }
    estatisticas(p, qtdPac);
    printf("LISTA DE PACIENTES:\n");
    for (int i = 0; i < qtdPac; i++)
    {
        imprimePaciente(p[i]);
    }
    for (int i = 0; i < qtdPac; i++)
    {
        liberaPaciente(p[i]);
    }
    free(p);
    return 0;
}

void estatisticas(Paciente **p, int qtdPac)
{
    printf("TOTAL PACIENTES: %d\n", qtdPac);
    if (calculaMedia(p, qtdPac) != -1)
    {
        printf("MEDIA IDADE (ANOS): %d\n", calculaMedia(p, qtdPac));
    }
    else
    {
        printf("MEDIA IDADE (ANOS): -\n");
    }
    printf("TOTAL LESOES: %d\n", contabilizaLesoes(p, qtdPac));
    printf("TOTAL CIRURGIAS: %d\n", contabilizaCirurgia(p, qtdPac));
}
int calculaMedia(Paciente **p, int qtdPac)
{
    int soma = 0;
    Data *dataBase = criaData(12, 9, 2023);
    for (int i = 0; i < qtdPac; i++)
    {
        soma += calculaIdadePaciente(p[i], dataBase);
    }
    liberaData(dataBase);
    if (qtdPac != 0)
    {
        return (soma / qtdPac);
    }
    else
    {
        return -1;
    }
}

int contabilizaLesoes(Paciente **p, int qtdPac)
{
    int soma = 0;
    for (int i = 0; i < qtdPac; i++)
    {
        soma += getNumLesoesPaciente(p[i]);
    }
    return soma;
}

int contabilizaCirurgia(Paciente **p, int qtdPac)
{
    int soma = 0;
    for (int i = 0; i < qtdPac; i++)
    {
        soma += qtdLesoesCirurgicasPaciente(p[i]);
    }
    return soma;
}