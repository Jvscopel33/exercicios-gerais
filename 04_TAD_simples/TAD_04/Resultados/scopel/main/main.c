#include <stdio.h>
#include "aluno.h"

int main()
{
    int qtdal;
    int apr = 0;
    scanf(" %d\n", &qtdal);
    tAluno alunos[qtdal];
    tAluno temp;
    for (int i = 0; i < qtdal; i++)
    {
        alunos[i] = LeAluno(alunos[i]);
    }
    for (int i = 0; i < qtdal; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (ComparaMatricula(alunos[i], alunos[j]) == -1)
            {
                temp = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = temp;
            }
        }
    }
    for (int i = 0; i < qtdal; i++)
    {
        if (VerificaAprovacao(alunos[i]))
        {
            ImprimeAluno(alunos[i]);
        }
    }
    return 0;
}