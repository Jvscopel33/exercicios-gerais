#include <stdio.h>
#include "vector.h"
#include "aluno.h"
#include "relatorio.h"

int main()
{
    int numAlunos;
    Vector *alunos = VectorConstruct();
    scanf(" %d\n", &numAlunos);
    for (int i = 0; i < numAlunos; i++)
    {
        tAluno *a = CriaAluno();
        LeAluno(a);
        VectorPushBack(alunos, a);
    }
    ImprimeRelatorio(alunos);
    VectorDestroy(alunos, DestroiAluno);
    return 0;
}