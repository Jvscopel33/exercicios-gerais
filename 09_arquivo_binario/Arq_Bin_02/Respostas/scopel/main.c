#include <stdio.h>
#include "base_alunos.h"

int main()
{
    tBaseAlunos *base = CriarBaseAlunos();

    char caminho[256];
    scanf("%s\n", caminho);

    LerBaseAlunos(base, caminho);
    printf("Coeficiente de Rendimento Medio da base de alunos: %.2f\n", GetCoeficienteRendimentoMedioBaseAlunos(base));
    DestruirBaseAlunos(base);

    return 0;
}