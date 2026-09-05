#include <stdio.h>
#include "jogada.h"
#include "jogo.h"
#include "tabuleiro.h"
#include "jogador.h"

int main()
{
    tJogo jogo;
    do
    {
        jogo = CriaJogo(jogo);
        ComecaJogo(jogo);
    } while (ContinuaJogo(jogo));
    return 0;
}