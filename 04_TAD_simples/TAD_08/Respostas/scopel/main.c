#include <stdio.h>
#include "departamento.h"

int main()
{
    int n;
    char nome[STRING_MAX];                               // nome do departamento
    char c1[STRING_MAX], c2[STRING_MAX], c3[STRING_MAX]; // nomes dos cursos do departamento
    int m1, m2, m3;                                      // médias de notas dos cursos do departamento
    char diretor[STRING_MAX];                            // nome do diretor do departamento
    scanf(" %d\n", &n);
    tDepartamento d[n];
    for (int i = 0; i < n; i++)
    {
        scanf(" %s\n", nome);
        scanf(" %s\n", diretor);
        scanf(" %s\n", c1);
        scanf(" %s\n", c2);
        scanf(" %s\n", c3);
        scanf(" %d %d %d\n", &m1, &m2, &m3);
        d[i] = criaDepartamento(c1, c2, c3, nome, m1, m2, m3, diretor);
    }
    ordenaPorMediaDepartamentos(d, n);
    for (int i = 0; i < n; i++)
    {
        imprimeAtributosDepartamento(d[i]);
    }
    return 0;
}