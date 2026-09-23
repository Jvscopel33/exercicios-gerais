#include <stdio.h>
#include <string.h>
#include "tDepartamento.h"
// #define STRING_MAX 50

// typedef struct departamento {
//     char curso1[STRING_MAX];
//     char curso2[STRING_MAX];
//     char curso3[STRING_MAX];
//     char diretor[STRING_MAX];
//     char nome[STRING_MAX];
//     int m1, m2, m3;
// } tDepartamento;

/**
 * @brief Cria um departamento com os dados passados via parâmetro
 *
 *
 * @param *curso1 Ponteiro para string que contém o nome do primeiro curso do departamento
 * @param *curso2 Ponteiro para string que contém o nome do segundo curso do departamento
 * @param *curso3 Ponteiro para string que contém o nome do terceiro curso do departamento
 * @param *nome Ponteiro para string que contém o nome do departamento
 * @param m1 Nota do primeiro curso (curso1)
 * @param m2 Nota do segundo curso (curso2)
 * @param m3 Nota do terceiro curso (curso3)
 * @param *diretor Ponteiro para string que contém o nome do diretor/chefe do departamento
 */
tDepartamento CriaDepartamento(char *curso1, char *curso2, char *curso3,
                               char *nome, int m1, int m2, int m3, char *diretor)
{
    tDepartamento d;
    strcpy(d.curso1, curso1);
    strcpy(d.curso2, curso2);
    strcpy(d.curso3, curso3);
    strcpy(d.nome, nome);
    strcpy(d.diretor, diretor);
    d.m1 = m1;
    d.m2 = m2;
    d.m3 = m3;
    return d;
}

/**
 * @brief Imprime os atributos de um departamento em tela
 *
 * @param depto - Um departamento que terá seus dados impressos em tela
 */

void ImprimeAtributosDepartamento(tDepartamento depto)
{
    int soma = 0;
    soma += depto.m1;
    soma += depto.m2;
    soma += depto.m3;
    float media = ((float)soma) / 3.0;
    printf("\n");
    printf("Departamento: %s\n", depto.nome);
    printf("\tDiretor: %s\n", depto.diretor);
    printf("\t1o curso: %s\n", depto.curso1);
    printf("\tMedia do 1o curso: %d\n", depto.m1);
    printf("\t2o curso: %s\n", depto.curso2);
    printf("\tMedia do 2o curso: %d\n", depto.m2);
    printf("\t3o curso: %s\n", depto.curso3);
    printf("\tMedia do 3o curso: %d\n", depto.m3);
    printf("\tMedia dos cursos: %.2f\n", media);
}

/**
 * @brief Ordena os departamentos de acordo com as médias das notas de cada um dos seus três cursos (da maior para a menor).
 *
 * @param *vetor_deptos - Ponteiro para um vetor de departamentos
 * @param num_deptos - O número de departamentos contidos no vetor_deptos
 */
void OrdenaDepartamentosPorMedia(tDepartamento *vetor_deptos, int num_deptos)
{
    for (int i = 0; i < num_deptos; i++)
    {

        for (int j = 0; j < num_deptos - 1 - i; j++)
        {
            int soma_j = 0;
            soma_j += vetor_deptos[j].m1;
            soma_j += vetor_deptos[j].m2;
            soma_j += vetor_deptos[j].m3;

            float media_j = ((float)soma_j) / 3.0;

            int soma_j1 = 0;
            soma_j1 += vetor_deptos[j].m1;
            soma_j1 += vetor_deptos[j].m2;
            soma_j1 += vetor_deptos[j].m3;

            float media_j1 = ((float)soma_j1) / 3.0;

            if (media_j1 > media_j)
            {
                tDepartamento temp;
                temp = vetor_deptos[j];
                vetor_deptos[j] = vetor_deptos[j + 1];
                vetor_deptos[j + 1] = temp;
            }
        }
    }
}
