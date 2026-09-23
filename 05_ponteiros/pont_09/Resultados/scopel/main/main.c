#include <stdio.h>
#include "pessoa.h"

int main()
{
    int n;
    scanf(" %d\n", &n);
    tPessoa p[n];
    for (int i = 0; i < n; i++)
    {
        p[i] = CriaPessoa();
    }
    for (int i = 0; i < n; i++)
    {
        LePessoa(&p[i]);
    }
    AssociaFamiliasGruposPessoas(&p);
    for (int i = 0; i < n; i++)
    {
        ImprimePessoa(&p[i]);
    }
    return 0;
}