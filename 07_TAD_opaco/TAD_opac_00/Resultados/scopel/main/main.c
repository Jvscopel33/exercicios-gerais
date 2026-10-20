#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"
#include "circulo.h"

int main()
{
    tCirculo c;
    tPonto p;
    float xc, yc, r;
    float x1, y1;

    scanf(" %f %f %f %f %f\n", &xc, &yc, &r, &x1, &y1);

    p = Pto_Cria(x1, y1);
    c = Circulo_Cria(xc, yc, r);

    printf("%d\n", Circulo_Interior(c, p));
    Circulo_Apaga(c);
    Pto_Apaga(p);
    return 0;
}