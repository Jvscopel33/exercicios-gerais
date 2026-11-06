#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encaminhamento.h"

#define MAX_NOME 100
#define MAX_INSTRU 200

/*
    Estrutura do tipo Encaminhamento contendo os atributos necessários para a manipulação
*/
struct _Encaminhamento
{
    char especialidade[MAX_NOME];
    char nomePaciente[MAX_NOME];
    char nomeMedico[MAX_NOME];
    char motivoDoEncaminhamento[MAX_INSTRU];
};

/*
    Função que cria uma Encaminhamento e retorna o seu endereço de memória
    @param especialidade: nome do medicamento prescrito na Encaminhamento
    @param nomePaciente: nome do paciente para quem a Encaminhamento foi prescrita
    @param nomeMedico: nome do médico que prescreveu a Encaminhamento
    @param motivoDoEncaminhamento: instruções para o uso do medicamento
    @return: endereço de memória da Encaminhamento criada
*/
Encaminhamento *criaEncaminhamento(char *especialidade, char *nomePaciente, char *nomeMedico, char *motivoDoEncaminhamento)
{
    Encaminhamento *t = (Encaminhamento *)calloc(1, sizeof(Encaminhamento));
    strcpy(t->especialidade, especialidade);
    strcpy(t->nomeMedico, nomeMedico);
    strcpy(t->nomePaciente, nomePaciente);
    strcpy(t->motivoDoEncaminhamento, motivoDoEncaminhamento);
    return t;
}

/*
    Função que lê os dados de uma Encaminhamento a partir da entrada padrão de acordo com a especificação
    @return: endereço de memória da Encaminhamento lida
*/
Encaminhamento *leEncaminhamento()
{
    Encaminhamento r;
    scanf("%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n", r.nomeMedico, r.nomePaciente, r.especialidade, r.motivoDoEncaminhamento);
    return criaEncaminhamento(r.especialidade, r.nomePaciente, r.nomeMedico, r.motivoDoEncaminhamento);
}

/*
    Função que calcula o preço de impressão de uma Encaminhamento de acordo com a especificação
    @param dado: ponteiro genérico para a Encaminhamento a ser calculada
    @param precoCaractere: preço por caractere utilizado no cálculo
    @return: preço de impressão da Encaminhamento
*/
float calculaPrecoImpressaoEncaminhamento(void *dado, float precoCaractere)
{
    int qtd_char = 0;

    qtd_char += strlen(((Encaminhamento *)dado)->motivoDoEncaminhamento);
    qtd_char += strlen(((Encaminhamento *)dado)->especialidade);
    qtd_char += strlen(((Encaminhamento *)dado)->nomeMedico);
    qtd_char += strlen(((Encaminhamento *)dado)->nomePaciente);

    return qtd_char * precoCaractere;
}

/*
    Função que imprime uma Encaminhamento de acordo com a especificação (veja os casos de teste)
    @param dado: ponteiro genérico para a Encaminhamento a ser impressa
*/
void imprimeEncaminhamento(void *dado)
{
    printf("- - ENCAMINHAMENTO - -\n");
    printf("PACIENTE: %s\n", ((Encaminhamento *)dado)->nomePaciente);
    printf("ESPECIALIDADE: %s\n", ((Encaminhamento *)dado)->especialidade);
    printf("MOTIVO: %s\n", ((Encaminhamento *)dado)->motivoDoEncaminhamento);
    printf("MEDICO: %s\n", ((Encaminhamento *)dado)->nomeMedico);
    printf("- - - - - - - - - - - -\n");
}

/*
    Função que desaloca uma Encaminhamento
    @param dado: ponteiro genérico para a Encaminhamento a ser desalocada
*/

void desalocaEncaminhamento(void *dado)
{
    dado = (Encaminhamento *)dado;
    free(dado);
}
