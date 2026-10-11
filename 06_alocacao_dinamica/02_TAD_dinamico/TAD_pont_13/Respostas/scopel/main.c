#include <stdio.h>
#include <stdlib.h>
#include "paciente.h"
#include "lesao.h"
#include "data.h"

int calculaMediaIdade(Paciente *p[], int qtd)
{
    int soma = 0;
    int media = 0;
    Data *dataBase = criaData(12, 9, 2023);
    for (int i = 0; i < qtd; i++)
    {
        soma += calculaIdadePaciente(p[i], dataBase);
    }
    media = soma / qtd;
    return media;
}

int main()
{
    Paciente *p[100];
    Lesao *l;
    int qtdPacientes = 0;
    int mediaIdade = 0;
    char cmd;
    scanf(" %c\n", &cmd);
    while (cmd != 'F')
    {
        if (cmd == 'P')
        {
            p[qtdPacientes] = lerPaciente();
            qtdPacientes++;
        }
        if (cmd == 'L')
        {
            l = lerLesao();
            for (int i = 0; i < qtdPacientes; i++)
            {
                vinculaLesaoPaciente(p[i], l);
            }
        }
        scanf(" %c\n", &cmd);
    }
    mediaIdade = calculaMediaIdade(p, qtdPacientes);
    printf("TOTAL PACIENTES: %d", qtdPacientes);
    printf("MEDIA IDADE (ANOS): %d", mediaIdade);
    
    for (int i = 0; i < qtdPacientes; i++)
    {
        liberaPaciente(p[i]);
    }
    free(p);
    return 0;
}