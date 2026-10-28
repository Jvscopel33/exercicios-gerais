#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main()
{
    int elementoBuscado;
    int indice;
    Array *a = CriarArray();
    LerArray(a);
    OrdenarArray(a);
    scanf(" %d\n", &elementoBuscado);
    indice = BuscaBinariaArray(a, elementoBuscado);
    if (indice >= 0)
    {
        printf("Elemento %d encontrado no índice %d.\n", elementoBuscado, indice);
    }
    else
    {
        printf("Elemento %d não encontrado no array (-1).\n", elementoBuscado);
    }
    DestruirArray(a);
    return 0;
}