#include <stdio.h>
#include "jogo.h"
#include "jogador.h"
#include "tabuleiro.h"
#include "jogada.h"

/**
 * Cria um jogo e retorna o jogo criado.
 *
 * @return o jogo criado.
 */
tJogo CriaJogo()
{
    tJogo jogo;
    jogo.tabuleiro = CriaTabuleiro();
    jogo.jogador1 = CriaJogador(ID_JOGADOR_1);
    jogo.jogador2 = CriaJogador(ID_JOGADOR_2);
    return jogo;
}

/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 *
 * @param jogo o jogo a ser iniciado.
 */
void ComecaJogo(tJogo jogo)
{

    while (!AcabouJogo(jogo))
    {
        jogo.tabuleiro = JogaJogador(jogo.jogador1, jogo.tabuleiro);
        ImprimeTabuleiro(jogo.tabuleiro);
        if (VenceuJogador(jogo.jogador1, jogo.tabuleiro))
        {
            printf("JOGADOR 1 Venceu!\n");
            return;
        }
        if (AcabouJogo(jogo))
        {
            break;
        }
        jogo.tabuleiro = JogaJogador(jogo.jogador2, jogo.tabuleiro);
        ImprimeTabuleiro(jogo.tabuleiro);
        if (VenceuJogador(jogo.jogador2, jogo.tabuleiro))
        {
            printf("JOGADOR 2 Venceu!\n");
            return;
        }
    }
    printf("Sem vencedor!\n");
    return;
}

/**
 * Verifica se o jogo acabou (se não há mais posições livres no tabuleiro).
 *
 * @param jogo o jogo atual.
 *
 * @return 1 se o jogo acabou, 0 caso contrário.
 */
int AcabouJogo(tJogo jogo)
{
    if (TemPosicaoLivreTabuleiro(jogo.tabuleiro))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/**
 * Verifica se o usuário deseja jogar novamente.
 *
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo()
{
    char cmd;
    printf("Jogar novamente? (s,n)\n");
    scanf(" %c\n", &cmd);
    while (cmd != 's' && cmd != 'n')
    {
        scanf(" %c\n", &cmd);
    }
    if (cmd == 's')
    {
        return 1;
    }
    return 0;
}
