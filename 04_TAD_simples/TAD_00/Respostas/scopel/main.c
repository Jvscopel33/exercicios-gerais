#include <stdio.h>
#include "ponto.h"

int main()
{
    float x1, x2, y1, y2;
    Ponto p1, p2;
    float dist;
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
    p1 = pto_atribui_x(p1, x1);
    p2 = pto_atribui_x(p2, x2);
    p1 = pto_atribui_y(p1, y1);
    p2 = pto_atribui_y(p2, y2);
    dist = pto_distancia(p1, p2);
    printf("%g", dist);
    return 0;
}