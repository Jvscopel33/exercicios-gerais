#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "base_alunos.h"

/**
 * @brief Estrutura para representar uma base de alunos.
 */
struct BaseAlunos
{
    tAluno **alunos;
    int qtdAlunos;
};

/**
 * @brief Função para criar uma nova base de alunos.
 *
 * @return Um ponteiro para a base de alunos recém-criada. Se houver erro na alocação de memória, o programa é encerrado.
 */
tBaseAlunos *CriarBaseAlunos()
{
    tBaseAlunos *b = (tBaseAlunos *)calloc(1, sizeof(tBaseAlunos));
    b->alunos = NULL;
    b->qtdAlunos = 0;
}

/**
 * @brief Função para destruir uma base de alunos.
 *
 * @param baseAlunos A base de alunos a ser destruída.
 */
void DestruirBaseAlunos(tBaseAlunos *baseAlunos)
{
    for (int i = 0; i < baseAlunos->qtdAlunos; i++)
    {
        DestruirAluno(baseAlunos->alunos[i]);
    }
    free(baseAlunos->alunos);
    free(baseAlunos);
}

/**
 * @brief Função para ler uma base de alunos de um arquivo binário.
 *
 * @param baseAlunos A base de alunos para ler o arquivo.
 * @param nomeArquivo O nome do arquivo a ser lido.
 */
void LerBaseAlunos(tBaseAlunos *baseAlunos, char *nomeArquivo)
{
    FILE *f = fopen(nomeArquivo, "r");
    fread(&baseAlunos->qtdAlunos, sizeof(int), 1, f);
    for (int i = 0; i < baseAlunos->qtdAlunos; i++)
    {
        baseAlunos->alunos = (tAluno **)realloc(baseAlunos->alunos, (i + 1) * sizeof(tAluno *));
        baseAlunos->alunos[i] = LeAluno(f);
    }
    fclose(f);
}

/**
 * @brief Função para obter o coeficiente de rendimento médio de uma base de alunos.
 *
 * @param baseAlunos A base de alunos para obter o coeficiente de rendimento médio.
 * @return O coeficiente de rendimento médio da base de alunos.
 */
float GetCoeficienteRendimentoMedioBaseAlunos(tBaseAlunos *baseAlunos)
{
    float soma = 0;
    for (int i = 0; i < baseAlunos->qtdAlunos; i++)
    {
        soma += GetCoeficienteRendimentoAluno(baseAlunos->alunos[i]);
    }
    return soma / baseAlunos->qtdAlunos;
}

// _BASE_ALUNOS_H_