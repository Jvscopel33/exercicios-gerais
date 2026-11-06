#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "fila.h"
#include "movel.h"

void DestroiElementoMovel(DataType elemento)
{
    DestroiMovel(elemento);
}

int main()
{
    Fila *f = FilaConstruct();
    int num;
    scanf(" %d\n", &num);
    char cmd[50];
    for (int i = 0; i < num; i++)
    {
        scanf(" %s", cmd);
        if (!strcmp(cmd, "ENTRADA"))
        {
            FilaPush(f, LeMovel());
        }
        else if (!strcmp(cmd, "PRODUZIR"))
        {
            tMovel *m = FilaPop(f);
            ImprimeMovel(m);
            DestroiMovel(m);
        }
    }
    FilaDestroy(f, DestroiElementoMovel);
    return 0;
}