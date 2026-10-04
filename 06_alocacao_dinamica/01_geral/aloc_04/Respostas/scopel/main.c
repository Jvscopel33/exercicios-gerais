#include <stdio.h>
#include "utils_char2.h"

int main()
{
    char *vet;
    vet = CriaVetorTamPadrao();
    int tam = 10;
    vet = LeVetor(vet, &tam);
    ImprimeString(vet);
    LiberaVetor(vet);
}