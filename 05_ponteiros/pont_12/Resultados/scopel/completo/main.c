#include <stdio.h>
#include "vetor.h"

int somar(int n1, int n2)
{
    return n1 + n2;
}
int produto(int n1, int n2)
{
    return n1 * n2;
}
int main()
{

    int result;
    Vetor vet;
    LeVetor(&vet);
    result = AplicarOperacaoVetor(&vet, somar);
    printf("Soma: %d\n", result);
    result = AplicarOperacaoVetor(&vet, produto);
    printf("Produto: %d\n", result);
    return 0;
}