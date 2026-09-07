#include <stdio.h>
#include "livro.h"
// Estrutura que representa um livro
// typedef struct
// {
//     char titulo[100];  // Título do livro
//     char autor[50];    // Autor do livro
//     int anoPublicacao; // Ano de publicação do livro
// } tLivros;

/**
 * Lê os atributos de um livro a partir da entrada padrão (teclado).
 *
 * @return Um livro com os atributos lidos.
 */
tLivros lerLivro()
{
    tLivros l;
    scanf("%99[^\n]\n", l.titulo);
    scanf("%49[^\n]\n", l.autor);
    scanf(" %d\n", &l.anoPublicacao);
    return l;
}

/**
 * Imprime os atributos da TAD tLivros (título, autor e ano de publicação).
 *
 * @param livro O livro cujos atributos serão impressos
 */
void imprimeLivro(tLivros livro)
{
    printf("Titulo: %s\n", livro.titulo);
    printf("Autor: %s\n", livro.autor);
    printf("Ano de Publicacao: %d\n", livro.anoPublicacao);
}
