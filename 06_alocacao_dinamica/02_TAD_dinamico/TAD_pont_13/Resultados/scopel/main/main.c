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
    Lesao **lesoes = NULL;

    int qtdPacientes = 0;
    int mediaIdade = 0;
    int qtdLesao = 0;
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
            lesoes = realloc(lesoes, (qtdLesao + 1) * sizeof(Lesao *));
            lesoes[qtdLesao] = lerLesao();

            for (int i = 0; i < qtdPacientes; i++)
            {
                if (!strcmp(getCartaoSusLesao(lesoes[qtdLesao]), getCartaoSusPaciente(p[i])))
                {
                    vinculaLesaoPaciente(p[i], lesoes[qtdLesao]);
                    if (verificaCirurgicaLesao(lesoes[qtdLesao]))
                    {
                        malig++;
                    }
                    break;
                }
            }
            qtdLesao++;
        }
        scanf(" %c\n", &cmd);
    }

    mediaIdade = calculaMediaIdade(p, qtdPacientes);

    printf("TOTAL PACIENTES: %d\n", qtdPacientes);
    printf("MEDIA IDADE (ANOS): %d\n", mediaIdade);
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
    for (int i = 0; i < qtdLesao; i++)
    {
        liberaLesao(lesoes[i]);
    }
    free(lesoes);
    return 0;
}