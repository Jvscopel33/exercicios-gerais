#include <stdio.h>

#define MAX_STRING 1000
void ImprimeInvertido(char *string)
{
    if (*string == '\0')
    {
        return;
    }
    else if (*string == ' ')
    {
        printf("%c", *string);
    }
    else
    {
        ImprimeInvertido(string - 1);
        printf(" ");
    }
}
int main()
{
    char string[MAX_STRING];
    scanf("%999[^\n]", string);
    ImprimeInvertido(string);
    printf("\n");
    return 0;
}