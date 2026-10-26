#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "livro.h"

// Estrutura que representa um livro
struct Livros
{
    char *titulo;
    char *autor;
    int ano;
};

/**
 * Cria um livro "vazio". Ponteiros devem receber null e os atributos numéricos valor -1;
 *
 * @return Um ponteiro para um livro livro "vazio"
 */
tLivros *CriaLivro()
{
    tLivros *l = (tLivros *)calloc(1, sizeof(tLivros));
    l->ano = -1;
    l->autor = NULL;
    l->titulo = NULL;
}

/**
 * Lê os atributos de um livro a partir da entrada padrão (teclado).
 *
 * @param livro Um ponteiro para um livro que receberá os atributos lidos
 */
void LerLivro(tLivros *livro)
{
    int qtdLet = 0;
    char let;
    while (1)
    {
        scanf("%c", &let);
        if (let == '\n')
        {
            break;
        }
        livro->titulo = realloc(livro->titulo, (qtdLet + 1) * sizeof(char));
        livro->titulo[qtdLet] = let;
        qtdLet++;
    }
    livro->titulo = realloc(livro->titulo, (qtdLet + 1) * sizeof(char));
    livro->titulo[qtdLet] = '\0';
    qtdLet = 0;
    while (1)
    {
        scanf("%c", &let);
        if (let == '\n')
        {
            break;
        }
        livro->autor = realloc(livro->autor, (qtdLet + 1) * sizeof(char));
        livro->autor[qtdLet] = let;
        qtdLet++;
    }
    livro->autor = realloc(livro->autor, (qtdLet + 1) * sizeof(char));
    livro->autor[qtdLet] = '\0';
    scanf(" %d\n", &livro->ano);
}

/**
 * Imprime os atributos da TAD tLivros (título, autor e ano de publicação).
 *
 * @param livro Um ponteiro para o livro cujos atributos serão impressos
 */
void ImprimeLivro(tLivros *livro)
{
    printf("Titulo: %s\n", livro->titulo);
    printf("Autor: %s\n", livro->autor);
    printf("Ano de Publicacao: %d\n\n", livro->ano);
}

/**
 * Retorna o título do livro.
 *
 * @param livro Ponteiro para o livro cujo título será retornado.
 * @return O título do livro.
 */
char *getTitulo(tLivros *livro)
{
    return livro->titulo;
}

/**
 * Função para liberar toda a memória alocada por um livro
 *
 * @param livro Um ponteiro para o livro cujos atributos serão apagados/liberados
 */

void ApagaLivro(tLivros *livro)
{
    free(livro->titulo);
    free(livro->autor);
    free(livro);
}
