#include <stdio.h>
#include <stdlib.h>
#include "paciente.h"
#include "lesao.h"
#include "data.h"

int main()
{
    Paciente *p[100];
    Lesao *l;
    int qtdPacientes = 0;
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
    return 0;
}