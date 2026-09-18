#include <stdio.h>
#define MAX_COLUNA 100
#define MAX_LINHA 100
#define MAX_COMAND 4
typedef struct
{
    int m, n;
    int matriz[MAX_COLUNA][MAX_LINHA];

} tTabuleiro;
typedef struct
{
    tTabuleiro tabuleiro;
    int xi, yi;
    int xf, yf;
    char comandos[MAX_COMAND];
} tJogo;
tJogo leJogo();
void leMatriz(tTabuleiro tabuleiro);
void leComando(tJogo jogo);
tJogo movimentaJogo();
int jogoContinua(tJogo jogo);
int ehPossivelMudar(tJogo jogo);
void mudaPosicao(tJogo jogo, int posComand);
int main()
{
    tJogo jogo;
    jogo = leJogo();
    jogo = movimentaJogo(jogo);
    return 0;
}
tJogo leJogo()
{
    tJogo jogo;
    scanf("%d %d", &jogo.tabuleiro.m, jogo.tabuleiro.n);
    leMatriz(jogo.tabuleiro);
    leComando(jogo);
}
void leMatriz(tTabuleiro tabuleiro)
{
    for (int i = 0; i < tabuleiro.m; i++)
    {
        for (int j = 0; j < tabuleiro.n; j++)
        {
            scanf("%d", &tabuleiro.matriz[i][j]);
        }
    }
}
void leComando(tJogo jogo)
{
    scanf("%3s", jogo.comandos);
}
tJogo movimentaJogo(tJogo jogo)
{
    while (jogoContinua(jogo))
    {
        for (int i = 0; i < MAX_COMAND; i++)
        {
            if (ehPossivelMudar(jogo))
            {
                mudaPosicao(jogo, i);
            }
            else
            {
                mudaPosicao(jogo, )
            }
        }
    }
}