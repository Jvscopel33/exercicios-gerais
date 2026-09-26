#include <stdio.h>
#include "utils.h"

int main()
{
    int tamanho;
    float result;
    scanf(" %d\n", &tamanho);
    int *vet = CriaVetor(tamanho);
    LeVetor(vet, tamanho);
    result = CalculaMedia(vet, tamanho);
    printf("%.2f\n", result);
    LiberaVetor(vet);
    return 0;
}