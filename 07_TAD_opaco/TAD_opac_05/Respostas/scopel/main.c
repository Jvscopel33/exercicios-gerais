#include <stdio.h>
#include <stdlib.h>
#include "conta.h"
#include "usuario.h"
#include "banco.h"

int main()
{
    char cmd;
    tBanco *b = CriaBanco();
    while (1)
    {
        scanf(" %c\n", &cmd);
        if (cmd == 'F')
        {
            break;
        }
        else if (cmd == 'A')
        {
            AbreContaBanco(b);
        }
        else if (cmd == 'D')
        {
            DepositoContaBanco(b);
        }
        else if (cmd == 'S')
        {
            SaqueContaBanco(b);
        }
        else if (cmd == 'T')
        {
            TransferenciaContaBanco(b);
        }
    }
    ImprimeRelatorioBanco(b);
    DestroiBanco(b);
    return 0;
}