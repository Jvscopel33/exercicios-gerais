#include <stdio.h>
int main()
{
    int n;
    int num = 1;
    int linha;
    scanf("%d", &n);
    if (n < 1)
    {
        return 0;
    }
    for (linha = 0; linha < n; linha++)
    {
        for (int coluna = 0; coluna <= linha; coluna++)
        {
            printf("%d ", num);
            num++;
        }
        printf("\n");
    }
    return 0;
}