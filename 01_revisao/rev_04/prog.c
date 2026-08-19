#include <stdio.h>

int main()
{
    int n;
    int result[20];
    int i = 0;
    int qtd;
    scanf("%d", &n);
    while (n > 0)
    {
        result[i] = n % 8;
        n = n / 8;
        i++;
    }
    for (i = i - 1; i >= 0; i--)
    {
        printf("%d", result[i]);
    }
    return 0;
}