#include <stdio.h>
#define TAM_MAX 1000
int main()
{
    int n;
    int livros[TAM_MAX] = {0};
    int flag = 0;
    int count;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &livros[i]);
    }
    for (int i = 0; i < n; i++)
    {
        count = 0;
        for (int j = 0; j < n; j++)
        {
            if (livros[i] == livros[j])
            {
                count++;
            }
        }
        if (count == 1)
        {
            printf("%d ", livros[i]);
            flag++;
        }
    }
    if (!flag)
    {
        printf("NENHUM");
    }
    return 0;
}