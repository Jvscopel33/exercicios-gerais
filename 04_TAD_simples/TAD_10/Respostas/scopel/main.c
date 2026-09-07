#include <stdio.h>
#include "livro.h"
#include "biblioteca.h"

// Lista de operacoes:
// 1 - Cadastrar livros.
// 2 - Remover livros.
// 3 - Listar todos os livros cadastrados.
int main()
{
    printf("Lista de operacoes:\n");
    printf("1 - Cadastrar livros.\n");
    printf("2 - Remover livros.\n");
    printf("3 - Listar todos os livros cadastrados.\n");
    int n;
    int cmd;
    tBiblioteca b;
    b = inicializarBiblioteca();
    scanf(" %d\n", &n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %d\n", &cmd);
        if (cmd == 1)
        {
            b = adicionarLivroNaBiblioteca(b, lerLivro());
        }
        else if (cmd == 2)
        {
            char n[100];
            scanf(" %s\n", n);
            b = removerLivroDaBiblioteca(b, n);
        }
        else if (cmd == 3)
        {
            listarLivrosDaBiblioteca(b);
        }
        else
        {
            printf("Operacao invalida!\n");
            return 0;
        }
    }
    return 0;
}