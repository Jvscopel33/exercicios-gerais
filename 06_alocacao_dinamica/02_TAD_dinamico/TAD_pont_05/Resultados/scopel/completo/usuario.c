#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
// typedef struct Usuario {
//     char nome[50]; /**< Nome do usuário. */
//     char cpf[15]; /**< CPF do usuário. */
// } tUsuario;

/**
 * @brief Cria um novo usuário.
 * Se não for possível alocar memória, o programa é encerrado.
 *
 * @return Um ponteiro para o novo usuário criado.
 */
tUsuario *CriaUsuario()
{
    tUsuario *u = (tUsuario *)calloc(1, sizeof(tUsuario));
    if (u == NULL)
    {
        printf("DEU RUIM NA ALOCACAO DO USUARIO\n");
        exit(1);
    }
    return u;
}

/**
 * @brief Desaloca a memória de um usuário.
 *
 * @param user Ponteiro para o usuário a ser destruído.
 */
void DestroiUsuario(tUsuario *user)
{
    free(user);
}

/**
 * @brief Lê os dados de um usuário da entrada padrão.
 *
 * @param user Ponteiro para o usuário a ser lido.
 */
void LeUsuario(tUsuario *user)
{
    scanf(" %s", user->nome);
    scanf(" %s", user->cpf);
}

/**
 * @brief Imprime os dados de um usuário.
 *
 * @param user Ponteiro para o usuário a ser impresso.
 */
void ImprimeUsuario(tUsuario *user)
{
    printf("Nome: %s\n", user->nome);
    printf("CPF: %s\n", user->cpf);
}
