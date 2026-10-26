#include <stdio.h>
#include <stdlib.h>
#include "empresa.h"
#include "funcionario.h"

int main()
{
    int qtdEmpresas = 0;
    tEmpresa **empresas;
    scanf(" %d", &qtdEmpresas);
    empresas = (tEmpresa **)calloc(qtdEmpresas, sizeof(tEmpresa *));
    for (int i = 0; i < qtdEmpresas; i++)
    {
        empresas[i] = CriaEmpresa();
        LeEmpresa(empresas[i]);
    }
    for (int i = 0; i < qtdEmpresas; i++)
    {
        ImprimeEmpresa(empresas[i]);
        printf("\n");
    }
    for (int i = 0; i < qtdEmpresas; i++)
    {
        ApagaEmpresa(empresas[i]);
    }
    free(empresas);
    return 0;
}