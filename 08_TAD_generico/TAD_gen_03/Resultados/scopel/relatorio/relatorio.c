#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "vector.h"

float calculaMedia(Vector *alunos);
int qtdAlunosAprovados(Vector *alunos);
int qtdGenero(Vector *alunos, char genero);
float calculaPorcentagem(int qtdRelativa, int qtdTotal);

/**
 * @brief Imprime o relatorio de uma coleção de alunos.
 * O relatorio deve possuir a media das notas, porcentagem de alunos aprovados e porcentagem de cada gênero.
 *
 * @param alunos Ponteiro para o vetor de alunos.
 */
void ImprimeRelatorio(Vector *alunos)
{
    printf("Media das notas: %.2f\n", calculaMedia(alunos));
    printf("Porcentagem de alunos aprovados: %.2f%%\n", calculaPorcentagem(qtdAlunosAprovados(alunos), VectorSize(alunos)));
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f%%\n", calculaPorcentagem(qtdGenero(alunos, 'M'), VectorSize(alunos)));
    printf("Feminino: %.2f%%\n", calculaPorcentagem(qtdGenero(alunos, 'F'), VectorSize(alunos)));
    printf("Outro: %.2f%%\n", calculaPorcentagem(qtdGenero(alunos, 'O'), VectorSize(alunos)));
}

int qtdGenero(Vector *alunos, char genero)
{
    int qtd = 0;
    for (int i = 0; i < VectorSize(alunos); i++)
    {
        if (GetGeneroAluno(VectorGet(alunos, i)) == genero)
        {
            qtd++;
        }
    }
    return qtd;
}

float calculaPorcentagem(int qtdRelativa, int qtdTotal)
{
    return (((float)qtdRelativa / qtdTotal) * 100);
}
float calculaMedia(Vector *alunos)
{
    float soma = 0;
    for (int i = 0; i < VectorSize(alunos); i++)
    {
        soma += GetNotaAluno(VectorGet(alunos, i));
    }
    return (soma / VectorSize(alunos));
}

int qtdAlunosAprovados(Vector *alunos)
{
    int soma = 0;
    for (int i = 0; i < VectorSize(alunos); i++)
    {
        if (GetNotaAluno(VectorGet(alunos, i)) >= 6)
        {
            soma++;
        }
    }
    return soma;
}
// _RELATORIO_H_
