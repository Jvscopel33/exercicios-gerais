#include <stdio.h>
#include <stdlib.h>
#include "agendatarefas.h"

typedef struct
{
    void *tarefa;
    int prioridade;
    void (*executa)(void *);
    void (*destroi)(void *);
} Tarefa;

struct agendatarefas
{
    Tarefa **tarefas;
    int numTare;
};

Tarefa *CriaTarefa()
{
    Tarefa *t = (Tarefa*)calloc(1, sizeof(Tarefa));
    t->prioridade = 0;
    t->tarefa = NULL;
    return t;
}
/**
 * @brief Cria uma variável para um tipo genérico que representa uma Agenda de Tarefas
 *
 * @param numTare A quantidade de tarefas que serão armazenadas no agendador
 *
 * @return Um ponteiro para a agenda de tarefas
 */
tAgendaTarefas *CriaAgendaDeTarefas(int numTare)
{
    tAgendaTarefas *t = (tAgendaTarefas *)calloc(1, sizeof(tAgendaTarefas));
    t->tarefas = NULL;
    t->numTare = 0;
    return t;
}

/**
 * @brief Destroi a agenda de tarefas (libera a memória)
 *
 * @param tar - A agenda que terá seu conteúdo liberado/destruído
 */
void DestroiAgendaDeTarefas(tAgendaTarefas *tar)
{
    for (int i = 0; i < tar->numTare; i++)
    {
        tar->tarefas[i]->destroi(tar->tarefas-)
    }
    free(tar->data);
    free(tar);
}

/**
 * @brief Cadastra uma tarefa em um agendador de tarefas
 *
 * @param tar - Pointeiro para a agenda de tarefas
 * @param prioridade - Prioridade de execução da nova tarefa
 * @param tarefa - Ponteiro para nova tarefa a ser executada
 * @param executa - Ponteiro para função (callback) que será chamada quando for a hora de executar a tarefa
 * @param destroi - Ponteiro para função (callback) que será chamada quando for a hora de destruir a tarefa (liberar a memória)
 *
 */
void CadastraTarefaNaAgenda(tAgendaTarefas *tar, int prioridade, void *tarefa, void (*executa)(void *), void (*destroi)(void *))
{
    tar->data = (void **)realloc(tar->data, (tar->numTare + 1) * sizeof(void *));
    tar->prioridade = prioridade;
    tar->data[tar->numTare] = tarefa;
    tar->executa = executa;
    tar->destroi = destroi;
    tar->numTare++;
}

/**
 * @brief Executa as tarefas que estão salvas na agenda de tarefas passada como parâmetro.
 *
 * @param tar Agenda de tarefas
 *
 */
void ExecutarTarefasDaAgenda(tAgendaTarefas *tar)
{
    for (int i = 0; i < tar->numTare; i++)
    {
        tar->executa(tar->data[i]);
    }
}
