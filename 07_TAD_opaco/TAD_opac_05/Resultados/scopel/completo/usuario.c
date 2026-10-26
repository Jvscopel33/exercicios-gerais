#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"

struct Usuario
{
    char *nome;
    char cpf[18];
};
/**
 * @brief Cria um novo usuário.
 * Se não for possível alocar memória, o programa é encerrado.
 *
 * @return Um ponteiro para o novo usuário criado.
 */
tUsuario *CriaUsuario()
{
    tUsuario *u = (tUsuario *)calloc(1, sizeof(tUsuario));
    u->nome = NULL;
    return u;
}

/**
 * @brief Desaloca a memória de um usuário.
 *
 * @param user Ponteiro para o usuário a ser destruído.
 */
void DestroiUsuario(tUsuario *user)
{
    free(user->nome);
    free(user);
}

/**
 * @brief Lê os dados de um usuário da entrada padrão.
 *
 * @param user Ponteiro para o usuário a ser lido.
 */
void LeUsuario(tUsuario *user)
{
    int qtdLet = 0;
    char let;
    while (1)
    {
        scanf("%c", &let);
        if (let == ' ')
        {
            break;
        }
        user->nome = (char *)realloc(user->nome, (qtdLet + 1) * sizeof(char));
        user->nome[qtdLet] = let;
        qtdLet++;
    }
    user->nome = (char *)realloc(user->nome, (qtdLet + 1) * sizeof(char));
    user->nome[qtdLet] = '\0';
    scanf(" %s ", user->cpf);
}

/**
 * @brief Imprime os dados de um usuário.
 *
 * @param user Ponteiro para o usuário a ser impresso.
 */

void ImprimeUsuario(tUsuario *user)
{
    printf("Nome: %s\nCPF: %s\n", user->nome, user->cpf);
}
