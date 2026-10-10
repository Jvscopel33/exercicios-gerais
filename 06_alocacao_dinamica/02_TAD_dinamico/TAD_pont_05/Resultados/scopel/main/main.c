#include <stdio.h>
#include "banco.h"
#include "conta.h"
#include "usuario.h"

int main()
{
    tBanco *b = CriaBanco();
    char cmd;
    scanf(" %c\n", &cmd);
    while (cmd != 'F')
    {
        if (cmd == 'S')
        {
            SaqueContaBanco(b);
        }
        else if (cmd == 'D')
        {
            DepositoContaBanco(b);
        }
        else if (cmd == 'T')
        {
            TransferenciaContaBanco(b);
        }
        else if (cmd == 'A')
        {
            AbreContaBanco(b);
        }
        else if (cmd == 'R')
        {
            ImprimeRelatorioBanco(b);
        }
        scanf(" %c\n", &cmd);
    }
    DestroiBanco(b);
    return 0;
}