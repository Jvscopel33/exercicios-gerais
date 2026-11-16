#include <stdio.h>
#include <stdlib.h>

#include "gerenciadorpacotes.h"
#include "pacote.h"

struct gerenciadorpacotes
{
    tPacote **pacotes;
    int qtdPacotes;
};

/**
 * @brief Cria uma TAD que gerencia pacotes. O pacote é um TAD genérico.
 *
 *
 * @return O gerenciador de pacotes
 */
tGerenciador *CriaGerenciador();

/**
 * @brief Adiciona um pacote ao gerenciador de pacotes.
 *
 * @param geren O gerenciador de pacotes que armazenará o pacote
 * @param pac O pacote que queremos adicionar no gerenciador.
 *
 */
void AdicionaPacoteNoGerenciador(tGerenciador *geren, tPacote *pac);

/**
 * @brief Destrói um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que será destruído (memória liberada)
 *
 */
void DestroiGerenciador(tGerenciador *geren);

/**
 * @brief Imprime um pacote específico do gerenciador de pacotes.
 *
 * @param geren - O gerenciador de pacotes que terá um pacote impresso
 * @param idx - O índice do pacote a ser impresso (começa em zero!)
 *
 */
void ImprimirPacoteNoIndice(tGerenciador *geren, int idx);

/**
 * @brief Imprime todos os pacotes de um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que terá seus pacotes impressos
 *
 */
void ImprimirTodosPacotes(tGerenciador *geren);

