#include <stdio.h>
#include <string.h>
#include <math.h>
#include "departamento.h"

// #define STRING_MAX 101 // número máximo de caracteres por string

// typedef struct Departamento {
//     char nome [STRING_MAX];     // nome do departamento
//     char c1[STRING_MAX], c2[STRING_MAX], c3[STRING_MAX];    // nomes dos cursos do departamento
//     int m1, m2, m3;     // médias de notas dos cursos do departamento
//     char diretor [STRING_MAX];    // nome do diretor do departamento
//     float media_geral;
// } tDepartamento;

/**
 * @brief Cria um departamento a partir de valores nomes dos cursos, nome do departamento, média por curso e nome do diretor.
 *
 * @param c1 Nome de um dos cursos do departamento.
 * @param c2 Nome de um dos cursos do departamento.
 * @param c3 Nome de um dos cursos do departamento.
 * @param nome Nome do departamento.
 * @param m1 Média do curso c1.
 * @param m2 Média do curso c2.
 * @param m3 Média do curso c3.
 * @param diretor Nome do diretor.
 * @return tDepartamento Departamento criado a partir dos valores nomes dos cursos, nome do departamento, média por curso e nome do diretor.
 */
tDepartamento criaDepartamento(char *c1, char *c2, char *c3, char *nome, int m1, int m2, int m3, char *diretor)
{
    tDepartamento d;
    d.m1 = m1;
    d.m2 = m2;
    d.m3 = m3;
    strcpy(d.nome, nome);
    strcpy(d.c1, c1);
    strcpy(d.c2, c2);
    strcpy(d.c3, c3);
    strcpy(d.diretor, diretor);
    d.media_geral = ((float)(m1 + m2 + m3)) / 3;

    return d;
}

/**
 * @brief Imprime os atributos do departamento, sendo eles: cursos, nome do departamento, média por curso e nome do diretor.
 *
 * @param depto Departamento cujos atributos serão impressos.
 */
void imprimeAtributosDepartamento(tDepartamento depto)
{
    printf("ATRIBUTOS:\n");
    printf("departamento => %s\n", depto.nome);
    printf("diretor => %s\n", depto.diretor);
    printf("curso1 => %s, media1 => %d\n", depto.c1, depto.m1);
    printf("curso2 => %s, media2 => %d\n", depto.c2, depto.m2);
    printf("curso3 => %s, media3 => %d\n", depto.c3, depto.m3);
    printf("media geral => %.2lf\n", depto.media_geral);
    printf("desvio padrao => %.2lf\n", calculaDesvioPadraoDepartamento(depto));
}

/**
 * @brief Verifica se a media inserida é valida, ou seja, pertence à [0, 10].
 *
 * @param media Valor a ser validado.
 * @return int Se é válida (1) ou não (0).
 */
int validaMediaDepartamento(int media)
{
    if (media >= 0 && media <= 10)
    {
        return 1;
    }
    return 0;
}

/**
 * @brief Calcula o Desvio Padrão das médias por curso de um departamento.
 *
 * @param depto Departamento cujo Desvio Padrão de médias por curso deve ser calculado.
 * @return double Valor do cálculo do Desvio Padrão.
 */
double calculaDesvioPadraoDepartamento(tDepartamento depto)
{
    double desvio = 0;
    desvio += pow((depto.m1 - depto.media_geral), 2);
    desvio += pow((depto.m2 - depto.media_geral), 2);
    desvio += pow((depto.m3 - depto.media_geral), 2);
    desvio = desvio / 3;
    desvio = sqrt(desvio);
    return desvio;
}

/**
 * @brief Calcula a média simples das notas dos cursos do departamento.
 *
 * @param depto Departamento cuja media simples deve ser calculada.
 * @return double Valor do calculo da média simples.
 */
double calculaMediaGeralDepartamento(tDepartamento depto)
{
    return (depto.m1 + depto.m2 + depto.m3) / 3;
}

/**
 * @brief Ordena o vetor de departamentos em ordem decrescente de acordo com as médias dos departamentos.
 *
 * @param d Vetor de departamentos a ser ordenado.
 * @param tamanho Tamanho do vetor a ser ordenado.
 */
void ordenaPorMediaDepartamentos(tDepartamento d[], int tamanho)
{
    tDepartamento temp;
    for (int i = 0; i < tamanho - 1; i++)
    {
        for (int j = 0; j < tamanho - i - 1; j++)
        {
            if (d[j].media_geral < d[j + 1].media_geral)
            {
                temp = d[j];
                d[j] = d[j + 1];
                d[j + 1] = temp;
            }
        }
    }
}
