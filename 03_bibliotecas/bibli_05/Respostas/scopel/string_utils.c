#include <stdio.h>
#include "string_utils.h"

/**
 * @brief Retorna o tamanho de uma string.
 * @param str A string para obter o tamanho.
 * @return O tamanho da string.
 */
int string_length(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

/**
 * @brief Copia uma string de origem para destino.
 * @param src A string de origem.
 * @param dest A string de destino.
 */
void string_copy(char *src, char *dest)
{
    int n;
    n = string_length(src);
    for (int i = 0; i < n; i++)
    {
        dest[i] = src[i];
    }
    dest[n] = '\0';
}

/**
 * @brief Converte todos os caracteres de uma string para maiúsculas.
 * @param str A string para converter.
 */
void string_upper(char *str)
{
    int n;
    n = string_length(str);
    {
        for (int i = 0; i < n; i++)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] = str[i] - 32;
            }
        }
        str[n] = '\0';
    }
}

/**
 * @brief Converte todos os caracteres de uma string para minúsculas.
 * @param str A string para converter.
 */
void string_lower(char *str)
{
    int n;
    n = string_length(str);
    {
        for (int i = 0; i < n; i++)
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] = str[i] + 32;
            }
        }
    }
    str[n] = '\0';
}

/**
 * @brief Inverte uma string.
 * @param str A string para inverter.
 */
void string_reverse(char *str)
{
    int n;
    n = string_length(str);
    char temp[n];
    for (int i = 0; i < n / 2; i++)
    {
        temp[i] = str[i];
        str[i] = str[n - 1 - i];
        str[n - 1 - i] = temp[i];
    }
}
