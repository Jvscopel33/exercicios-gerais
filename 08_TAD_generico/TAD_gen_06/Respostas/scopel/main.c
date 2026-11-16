#include <stdio.h>
#include <stdlib.h>
#include "matrizgenerica.h"
#include "numcomplexo.h"

typedef enum
{
    INT = 0,
    FLOAT = 2,
    DOUBLE = 3,
    CPLX = 4
} Type;

void leMatriz(tMatrizGenerica *m, int tipo)
{

    for (int i = 0; i < ObtemNumeroLinhasMatrizGenerica(m); i++)
    {
        for (int j = 0; j < ObtemNumeroColunasMatrizGenerica(m); j++)
        {
            if (tipo == INT)
            {
                int data;
                scanf(" %d", &data);
                AtribuiElementoMatrizGenerica(m, i, j, &data);
            }
            else if (tipo == FLOAT)
            {
                float data;
                scanf(" %f", &data);
                AtribuiElementoMatrizGenerica(m, i, j, &data);
            }
            else if (tipo == DOUBLE)
            {
                double data;
                scanf(" %lf", &data);
                AtribuiElementoMatrizGenerica(m, i, j, &data);
            }
            else if (tipo == CPLX)
            {
                float real, img;
                scanf(" %f %f", &real, &img);
                tNumComplexo *num = CriaNumComplexo(real, img);
                AtribuiElementoMatrizGenerica(m, i, j, num);
            }
        }
    }
}

int main()
{
    int linhas, colunas;

    int tipo;

    printf("Digite o número de linhas, colunas e o tipo da matriz (0 – inteiro, 1 – float, 2 – double, 3 – char, 4 – número complexo):\n");

    scanf(" %d %d %d\n", &linhas, &colunas, &tipo);
    tMatrizGenerica *m = NULL;
    if (tipo == INT)
    {
        m = CriaMatrizGenerica(linhas, colunas, sizeof(int));
        leMatriz(m, tipo);
    }
    else if (tipo == FLOAT)
    {
        m = CriaMatrizGenerica(linhas, colunas, sizeof(float));
        leMatriz(m, tipo);
    }
    else if (tipo == DOUBLE)
    {
        m = CriaMatrizGenerica(linhas, colunas, sizeof(double));
        leMatriz(m, tipo);
    }
    else if (tipo == CPLX)
    {
        m = CriaMatrizGenerica(linhas, colunas, RetornaNumBytesComplexo());
        leMatriz(m, tipo);
    }

    // Digite a operação desejada
    // 1 - Apenas imprimir a matriz
    // 2 - Converter para o tipo complexo e imprimir
    // 3 - Calcular e imprimir a multiplicacao da matriz pela sua transposta.

    while (1)
    {
        int cmd;
        printf("Digite a operação desejada\n");
        printf("\t1 - Apenas imprimir a matriz\n");
        printf("\t2 - Converter para o tipo complexo e imprimir\n");
        printf("\t3 - Calcular e imprimir a multiplicacao da matriz pela sua transposta.\n");

        scanf(" %d\n", &cmd);

        if (cmd == 1)
        {
            if (tipo == 0 || tipo == 1 || tipo == 2 || tipo == 3)
            {
                ImprimirMatrizGenerica(m, printf);
            }
            else
            {
                ImprimirMatrizGenerica(m, ImprimeNumeroComplexo);
            }
        }
        else if (cmd == 2)
        {
            ConverteTipoMatriz(m, RetornaNumBytesComplexo(), );
        }
    }
}