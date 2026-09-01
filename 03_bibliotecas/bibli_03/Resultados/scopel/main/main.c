#include <stdio.h>
#include "data.h"

int main()
{
    int d1, m1, a1;
    int d2, m2, a2;
    int oldData;
    int difData;
    scanf("%d", &d1);
    getchar();
    scanf(" %d", &m1);
    getchar();
    scanf(" %d", &a1);
    getchar();
    scanf(" %d", &d2);
    getchar();
    scanf(" %d", &m2);
    getchar();
    scanf(" %d", &a2);
    if (verificaDataValida(d1, m1, a1) && verificaDataValida(d2, m2, a2))
    {
        printf("Primeira data: ");
        imprimeDataExtenso(d1, m1, a1);
        printf("\n");
        printf("Segunda data: ");
        imprimeDataExtenso(d2, m2, a2);
        printf("\n");
        oldData = comparaData(d1, m1, a1, d2, m2, a2);
        if (oldData == 1)
        {
            printf("A segunda data eh mais antiga\n");
        }
        else if (oldData == -1)
        {
            printf("A primeira data eh mais antiga\n");
        }
        else
        {
            printf("As datas sao iguais\n");
        }
        difData = calculaDiferencaDias(d1, m1, a1, d2, m2, a2);
        printf("A diferenca em dias entre as datas eh: %02d dias\n", difData);
    }
    else
    {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
    }
}