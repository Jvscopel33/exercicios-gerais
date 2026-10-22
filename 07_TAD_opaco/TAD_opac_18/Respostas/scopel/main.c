#include <stdio.h>
#include <stdlib.h>
#include "agencia.h"
#include "operacao.h"
#include "conta.h"

int main()
{
    tAgencia *a = CriaAgencia();
    printf("--- Agencia Bancaria ---");
    LeOperacoes(a);
    ImprimeOperacoesSuspeitas(a);
    ImprimeDoisCorrentistasComMaiorSaldo(a);
    ImprimeSaldoTotal(a);
    DestroiAgencia(a);
    return 0;
}