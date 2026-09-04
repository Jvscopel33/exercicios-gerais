#include <stdio.h>
#include "tabuleiro.h"
#include "jogador.h"
#include "jogada.h"

#define ID_JOGADOR_1 1
#define ID_JOGADOR_2 2

typedef struct
{
    int id;
} tJogador;

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
    printf("Jogador %d\n");
    printf("Digite uma posicao (x e y):\n");
    jogada = LeJogada();
    if (!EhPosicaoValidaTabuleiro(ObtemJogadaX(jogada), ObtemJogadaY(jogada)))
    {
        printf("Posicao invalida (OCUPADA - [%d,%d] )!", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
    }
    if (!EstaLivrePosicaoTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada)))
    {
        printf("Posicao invalida (OCUPADA - [%d,%d] )!", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
    }
    printf("Jogada [%d,%d]!", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
    tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, ObtemJogadaX(jogada), ObtemJogadaY(jogada));
    return tabuleiro;
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
    int win = 0;
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        win = 0;
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            if (jogador.id == 1)
            {
                if (tabuleiro.posicoes[i][j] == tabuleiro.peca1)
                {
                    win++;
                    if (win == 3)
                    {
                        return 1
                    }
                    continue;
                }
                else
                {
                }
            }
        }
    }
}
