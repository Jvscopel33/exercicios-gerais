#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tarefaimprime.h"

struct impr
{
    char msg[100];
};

/**
 * @brief Cria uma tarefa do tipo impressão em tela
 *
 * @param msg - A mensagem que deve ser impressa em tela
 *
 * @return Um ponteiro para a tarefa criada
 */
tImpr *CriaTarefaImprimir(char *msg)
{
    tImpr *t = (tImpr *)calloc(1, sizeof(tImpr));
    strcpy(t->msg, msg);
    return t;
}

/**
 * @brief Função que executa uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser executada
 *
 */

void ExecutaTarefaImprimir(void *imp)
{
    printf("\n%s", ((tImpr *)imp)->msg);
}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaImprimir(void *imp)
{
    imp = (tImpr *)imp;
    free(imp);
}
