#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"
#include "lesao.h"
#include "data.h"

int calculaMediaIdade(Paciente **p, int qtd)
{
    if (qtd == 0)
        return 0;

    int soma = 0;
    int media = 0;
    Data *dataBase = criaData(12, 9, 2023);
    for (int i = 0; i < qtd; i++)
    {
        soma += calculaIdadePaciente(p[i], dataBase);
    }
    media = soma / qtd;
    liberaData(dataBase);
    return media;
}

int main()
{
    Paciente **p = NULL;

    int qtdPacientes = 0;
    int mediaIdade = 0;
    int qtdLesao = 0;
    int vinc = 0;
    int malig = 0;
    char cmd;

    scanf(" %c\n", &cmd);
    while (cmd != 'F')
    {
        if (cmd == 'P')
        {
            p = realloc(p, (qtdPacientes + 1) * sizeof(Paciente *));
            p[qtdPacientes] = lerPaciente();
            qtdPacientes++;
        }
        else if (cmd == 'L')
        {
            vinc = 0;
            Lesao *l = lerLesao();
            for (int i = 0; i < qtdPacientes; i++)
            {
                if (!strcmp(getCartaoSusLesao(l), getCartaoSusPaciente(p[i])))
                {
                    vinculaLesaoPaciente(p[i], l);
                    vinc = 1;
                    if (verificaCirurgicaLesao(l))
                    {
                        malig++;
                    }
                    break;
                }
            }
            if (!vinc)
            {
                free(l);
            }
        }
        scanf(" %c\n", &cmd);
    }

    mediaIdade = calculaMediaIdade(p, qtdPacientes);

    printf("TOTAL PACIENTES: %d\n", qtdPacientes);
    if (mediaIdade)
    {
        printf("MEDIA IDADE (ANOS): %d\n", mediaIdade);
    }
    else
    {
        printf("MEDIA IDADE (ANOS): -\n");
    }
    for (int i = 0; i < qtdPacientes; i++)
    {
        qtdLesao += getNumLesoesPaciente(p[i]);
    }
    printf("TOTAL LESOES: %d\n", qtdLesao);
    printf("TOTAL CIRURGIAS: %d\n", malig);
    printf("LISTA DE PACIENTES:\n");

    for (int i = 0; i < qtdPacientes; i++)
    {
        imprimePaciente(p[i]);
    }
    for (int i = 0; i < qtdPacientes; i++)
    {
        liberaPaciente(p[i]);
    }
    free(p);
    return 0;
}