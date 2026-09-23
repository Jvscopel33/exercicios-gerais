#include <stdio.h>
#include "calculadora.h"

CalculatoraCallback operacoes[128];

float soma(float n1, float n2)
{
    return n1 + n2;
}
float sub(float n1, float n2)
{
    return n1 - n2;
}
float mult(float n1, float n2)
{
    return n1 * n2;
}
float divisao(float n1, float n2)
{
    if (n2 != 0)
    {
        return n1 / n2;
    }
    return 0;
}

void incializaOperacoes()
{
    operacoes['s'] = sub;
    operacoes['a'] = soma;
    operacoes['m'] = mult;
    operacoes['d'] = divisao;
}

int main()
{
    char cmd;
    float n1, n2;
    incializaOperacoes();
    while (1)
    {
        scanf(" %c\n", &cmd);
        scanf(" %f %f\n", &n1, &n2);
        CalculatoraCallback op;
        if (cmd == 'f')
        {
            break;
        }
        else if (cmd == 's')
        {
            op = operacoes[cmd];
            printf("%.2f - %.2f = %.2f\n", n1, n2, Calcular(n1, n2, op));
        }
        else if (cmd == 'a')
        {
            op = operacoes[cmd];
            printf("%.2f + %.2f = %.2f\n", n1, n2, Calcular(n1, n2, op));
        }
        else if (cmd == 'd')
        {
            op = operacoes[cmd];
            printf("%.2f / %.2f = %.2f\n", n1, n2, Calcular(n1, n2, op));
        }
        else if (cmd == 'm')
        {
            op = operacoes[cmd];
            printf("%.2f x %.2f = %.2f\n", n1, n2, Calcular(n1, n2, op));
        }
    }
    return 0;
}