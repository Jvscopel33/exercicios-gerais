#include <stdio.h>
#include "string_utils.h"

#define MAX_CHAR 100
int main()
{
    int cmd;
    char str[MAX_CHAR];
    char cp[MAX_CHAR];
    scanf("%[^\n]", str);
    while (1)
    {
        printf("1 - Tamanho da string\n2 - Copiar string\n3 - Converter string para letras maiusculas\n4 - Converter string para letras minusculas\n5 - Imprimir string ao contrario\n6 - Encerrar o programa\nOpcao escolhida: \n");
        scanf(" %d", &cmd);
        if (cmd == 6)
        {
            return 0;
        }
        else if (cmd == 1)
        {
            printf("Tamanho da string: %d\n\n", string_length(str));
        }
        else if (cmd == 2)
        {
            string_copy(str, cp);
            printf("String copiada: %s\n\n", cp);
        }
        else if (cmd == 3)
        {
            string_upper(str);
            printf("String convertida para maiusculas: %s\n\n", str);
        }
        else if (cmd == 4)
        {
            string_lower(str);
            printf("String convertida para minusculas: %s\n\n", str);
        }
        else if (cmd == 5)
        {
            string_reverse(str);
            printf("String invertida: %s\n\n", str);
        }
    }
    return 0;
}