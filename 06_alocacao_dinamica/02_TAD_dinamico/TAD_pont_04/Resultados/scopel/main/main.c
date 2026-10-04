#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

int main()
{
    int n;
    scanf(" %d\n", &n);
    tAluno **listaDeAlunos = (tAluno *)calloc(n, sizeof(tAluno *));
    for (int i = 0; i < n; i++)
    {
        listaDeAlunos[i] = CriaAluno();
    }
    for (int i = 0; i < n; i++)
    {
        LeAluno(listaDeAlunos[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            tAluno *temp;
            if (ComparaMatricula(listaDeAlunos[j], listaDeAlunos[j + 1]) == 1)
            {
                temp = listaDeAlunos[j + 1];
                listaDeAlunos[j + 1] = listaDeAlunos[j];
                listaDeAlunos[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (VerificaAprovacao(listaDeAlunos[i]))
        {
            ImprimeAluno(listaDeAlunos[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        ApagaAluno(listaDeAlunos[i]);
    }
    free(listaDeAlunos);
    return 0;
}