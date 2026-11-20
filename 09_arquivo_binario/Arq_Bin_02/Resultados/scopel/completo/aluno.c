#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aluno.h"
/**
 * @brief Estrutura para representar um aluno.
 */
struct Aluno
{
    char nome[100];
    char dataNascimento[11];
    char curso[50];
    int periodo;
    float coeficienteRendimento;
};

/**
 * @brief Função para criar um novo aluno.
 *
 * @param nome Nome do aluno.
 * @param dataNascimento Data de nascimento do aluno.
 * @param curso Curso em que o aluno está matriculado.
 * @param periodo Período do curso em que o aluno está.
 * @param coeficienteRendimento Coeficiente de rendimento do aluno.
 * @return Um ponteiro para o aluno recém-criado. Se houver erro na alocação de memória, o programa é encerrado.
 */
tAluno *CriarAluno(char *nome, char *dataNascimento, char *curso, int periodo, float coeficienteRendimento)
{
    tAluno *a = (tAluno *)calloc(1, sizeof(tAluno));
    strcpy(a->nome, nome);
    strcpy(a->dataNascimento, dataNascimento);
    strcpy(a->curso, curso);
    a->periodo = periodo;
    a->coeficienteRendimento = coeficienteRendimento;
    return a;
}

/**
 * @brief Função para destruir um aluno.
 *
 * @param aluno O aluno a ser destruído.
 */
void DestruirAluno(tAluno *aluno)
{
    free(aluno);
}

/**
 * @brief Função para ler um aluno de um arquivo binário.
 *
 * @param arquivo_binario O arquivo binário para ler o aluno.
 * @return Um ponteiro para o aluno lido.
 */
tAluno *LeAluno(FILE *arquivo_binario)
{
    tAluno a;
    
    fread(a.nome, sizeof(char), sizeof(a.nome), arquivo_binario);
    fread(a.dataNascimento, sizeof(char), sizeof(a.dataNascimento), arquivo_binario);
    fread(a.curso, sizeof(char), sizeof(a.curso), arquivo_binario);
    fread(&a.periodo, sizeof(int), 1, arquivo_binario);
    fread(&a.coeficienteRendimento, sizeof(float), 1, arquivo_binario);

    return CriarAluno(a.nome, a.dataNascimento, a.curso, a.periodo, a.coeficienteRendimento);
}

/**
 * @brief Função para obter o coeficiente de rendimento de um aluno.
 *
 * @param aluno O aluno para obter o coeficiente de rendimento.
 * @return O coeficiente de rendimento do aluno.
 */
float GetCoeficienteRendimentoAluno(tAluno *aluno)
{
    return aluno->coeficienteRendimento;
}

// _ALUNO_H_
