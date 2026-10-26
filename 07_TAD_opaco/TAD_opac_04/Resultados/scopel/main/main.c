#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

int main()
{
    tAluno **alunos = NULL;
    int qtdAlunosAlocados = 0;
    int qtdAlunosEntrada;
    scanf(" %d\n", &qtdAlunosEntrada);

    for (int i = 0; i < qtdAlunosEntrada; i++)
    {
        alunos = (tAluno **)realloc(alunos, (qtdAlunosAlocados + 1) * sizeof(tAluno *));
        alunos[qtdAlunosAlocados] = CriaAluno();
        LeAluno(alunos[qtdAlunosAlocados]);
        qtdAlunosAlocados++;
    }

    for (int i = 0; i < qtdAlunosAlocados; i++)
    {
        for (int j = 0; j < qtdAlunosAlocados - 1 - i; j++)
        {
            if (ComparaMatricula(alunos[j], alunos[j + 1]) > 0)
            {
                tAluno *temp;
                temp = alunos[j + 1];
                alunos[j + 1] = alunos[j];
                alunos[j] = temp;
            }
        }
    }

    for (int i = 0; i < qtdAlunosAlocados; i++)
    {
        if (VerificaAprovacao(alunos[i]))
        {
            ImprimeAluno(alunos[i]);
        }
    }

    for (int i = 0; i < qtdAlunosAlocados; i++)
    {
        ApagaAluno(alunos[i]);
    }
    free(alunos);
    return 0;
}