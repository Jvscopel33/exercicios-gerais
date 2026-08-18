#include <stdio.h>
#include <math.h>
typedef struct
{
    float x, y;
    float raio;
} tPonto;
tPonto lePonto()
{
    tPonto ponto;
    scanf("%f %f %f", &ponto.x, &ponto.y, &ponto.raio);
    return ponto;
}
int houveColisao(tPonto alvo, tPonto tiro)
{
    float dist;
    dist = sqrt(pow((alvo.x - tiro.x), 2) + pow((alvo.y - tiro.y), 2));
    if (dist <= tiro.raio + alvo.raio)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    tPonto tiro;
    tPonto alvo;
    alvo = lePonto();
    tiro = lePonto();
    if (houveColisao(alvo, tiro))
    {
        printf("ACERTOU");
    }
    else
    {
        printf("ERROU");
    }
    return 0;
}