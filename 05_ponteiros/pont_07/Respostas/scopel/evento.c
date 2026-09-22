#include <stdio.h>
#include "evento.h"
#include <string.h>

// #define MAX_EVENTOS 10

// //Estrutura para representar um evento no calendário.
// typedef struct {
//     char nome[50]; // Nome do evento.
//     int dia;       // Dia do evento.
//     int mes;       // Mês do evento.
//     int ano;       // Ano do evento.
// } Evento;

/**
 * Cadastra um novo evento no calendário e o insere na próxima posição do array.
 *
 * @param eventos Array de eventos onde o novo evento será cadastrado.
 * @param numEventos Ponteiro para o número atual de eventos cadastrados.
 */

void cadastrarEvento(Evento *eventos, int *numEventos)
{
    char nome[50]; // Nome do evento.
    int dia;       // Dia do evento.
    int mes;       // Mês do evento.
    int ano;       // Ano do evento.
    scanf(" %s\n", nome);
    scanf(" %d %d %d\n", &dia, &mes, &ano);
    eventos[*numEventos].dia = dia;
    eventos[*numEventos].mes = mes;
    eventos[*numEventos].ano = ano;
    strcpy(eventos[*numEventos].nome, nome);
    (*numEventos)++;
}

/**
 * Exibe todos os eventos cadastrados no calendário.
 *
 * @param eventos Array de eventos a serem exibidos.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void exibirEventos(Evento *eventos, int *numEventos)
{
    for (int i = 0; i < *numEventos; i++)
    {
        printf("%d - %s - %02d/%20d/%04d\n", i, eventos[i].nome, eventos[i].dia, eventos[i].mes, eventos[i].ano);
    }
}

/**
 * Troca a data de um evento específico no calendário.
 *
 * @param eventos Array de eventos onde o evento será modificado.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */

void trocarDataEvento(Evento *eventos, int *numEventos)
{
    
}

/**
 * Troca a posição de dois eventos, a partir do índice, dentro do array de eventos.
 *
 * @param eventos Array de eventos onde a troca será realizada.
 * @param indiceA Ponteiro para o primeiro índice.
 * @param indiceB Ponteiro para o segundo índice.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarIndicesEventos(Evento *eventos, int *indiceA, int *indiceB, int *numEventos);
