#include <stdio.h>
#include "tDepartamento.h"

int main()
{
    char curso1[STRING_MAX];
    char curso2[STRING_MAX];
    char curso3[STRING_MAX];
    char diretor[STRING_MAX];
    char nome[STRING_MAX];
    int m1, m2, m3;
    int n;
    scanf(" %d", &n);
    tDepartamento vetDep[n];
    for (int i = 0; i < n; i++)
    {
        scanf(" %s\n", nome);
        scanf(" %s\n", diretor);
        scanf(" %s\n", curso1);
        scanf(" %s\n", curso2);
        scanf(" %s\n", curso3);
        scanf(" %d %d %d\n", &m1, &m2, &m3);
        vetDep[i] = CriaDepartamento(curso1, curso2, curso3, nome, m1, m2, m3, diretor);
    }
    OrdenaDepartamentosPorMedia(vetDep, n);
    for (int i = 0; i < n; i++)
    {
        ImprimeAtributosDepartamento(vetDep[i]);
    }
    return 0;
}