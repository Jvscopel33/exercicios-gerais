#include <stdio.h>
#include "tabuleiro.h"
#include "jogador.h"
#include "jogada.h"

// #define ID_JOGADOR_1 1
// #define ID_JOGADOR_2 2

// typedef struct
// {
//     int id;
// } tJogador;

/**
 * Cria um jogador com o id passado como parâmetro e retorna o jogador criado.
 *
 * @param idJogador o id do jogador (1 ou 2).
 *
 * @return tJogador o jogador criado.
 */
tJogador CriaJogador(int idJogador)
{
    tJogador jogador;
    jogador.id = idJogador;
    return jogador;
}

/**
 * Recebe um jogador e um tabuleiro e retorna o tabuleiro com a jogada do jogador.
 *
 * @param jogador o jogador que fará a jogada.
 * @param tabuleiro o tabuleiro atual.
 *
 * @return o tabuleiro atualizado com a jogada do jogador.
 */
tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    tJogada jogada;
    while (1)
    {
        printf("Jogador %d\n", jogador.id);
        jogada = LeJogada();
        if (!EhPosicaoValidaTabuleiro(ObtemJogadaX(jogada), ObtemJogadaY(jogada)))
        {
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
            continue;
        }
        if (!EstaLivrePosicaoTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada)))
        {
            printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
            continue;
        }

        tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, ObtemJogadaX(jogada), ObtemJogadaY(jogada));
        printf("Jogada [%d,%d]!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
        return tabuleiro;
    }
}

/**
 * Recebe um jogador e um tabuleiro e retorna 1 se o jogador venceu e 0 caso contrário.
 *
 * @param jogador o jogador a ser verificado.
 * @param tabuleiro o tabuleiro atual.
 *
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 0, jogador.id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 1, jogador.id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, jogador.id))
    {
        return 1;
    }
    else if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 0, jogador.id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, jogador.id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 2, jogador.id))
    {
        return 1;
    }
    else if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, jogador.id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 1, jogador.id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, jogador.id))
    {
        return 1;
    }
    else if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 0, jogador.id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, jogador.id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, jogador.id))
    {
        return 1;
    }
    else if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, jogador.id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, jogador.id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, jogador.id))
    {
        return 1;
    }
    else if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 0, jogador.id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 0, jogador.id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, jogador.id))
    {
        return 1;
    }
    else if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 1, jogador.id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, jogador.id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 1, jogador.id))
    {
        return 1;
    }
    else if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, jogador.id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 2, jogador.id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, jogador.id))
    {
        return 1;
    }
    return 0;
}
