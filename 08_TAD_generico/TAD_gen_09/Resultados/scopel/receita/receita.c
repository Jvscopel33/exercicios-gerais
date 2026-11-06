#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "receita.h"

#define MAX_NOME 100
#define MAX_INSTRU 200

/*
    Estrutura do tipo Receita contendo os atributos necessários para a manipulação
*/
struct _Receita
{
    char nomeMedicamento[MAX_NOME];
    char nomePaciente[MAX_NOME];
    char nomeMedico[MAX_NOME];
    char instrucoes[MAX_INSTRU];
};

/*
    Função que cria uma receita e retorna o seu endereço de memória
    @param nomeMedicamento: nome do medicamento prescrito na receita
    @param nomePaciente: nome do paciente para quem a receita foi prescrita
    @param nomeMedico: nome do médico que prescreveu a receita
    @param instrucoes: instruções para o uso do medicamento
    @return: endereço de memória da receita criada
*/
Receita *criaReceita(char *nomeMedicamento, char *nomePaciente, char *nomeMedico, char *instrucoes)
{
    Receita *t = (Receita *)calloc(1, sizeof(Receita));
    strcpy(t->nomeMedicamento, nomeMedicamento);
    strcpy(t->nomeMedico, nomeMedico);
    strcpy(t->nomePaciente, nomePaciente);
    strcpy(t->instrucoes, instrucoes);
    return t;
}

/*
    Função que lê os dados de uma receita a partir da entrada padrão de acordo com a especificação
    @return: endereço de memória da receita lida
*/
Receita *leReceita()
{
    Receita r;
    scanf("%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n", r.nomeMedico, r.nomePaciente, r.nomeMedicamento, r.instrucoes);
    return criaReceita(r.nomeMedicamento, r.nomePaciente, r.nomeMedico, r.instrucoes);
}

/*
    Função que calcula o preço de impressão de uma receita de acordo com a especificação
    @param dado: ponteiro genérico para a receita a ser calculada
    @param precoCaractere: preço por caractere utilizado no cálculo
    @return: preço de impressão da receita
*/
float calculaPrecoImpressaoReceita(void *dado, float precoCaractere)
{
    int qtd_char = 0;

    qtd_char += strlen(((Receita *)dado)->instrucoes);
    qtd_char += strlen(((Receita *)dado)->nomeMedicamento);
    qtd_char += strlen(((Receita *)dado)->nomeMedico);
    qtd_char += strlen(((Receita *)dado)->nomePaciente);

    return qtd_char * precoCaractere;
}

/*
    Função que imprime uma receita de acordo com a especificação (veja os casos de teste)
    @param dado: ponteiro genérico para a receita a ser impressa
*/
void imprimeReceita(void *dado)
{
    printf("- - RECEITA - -\n");
    printf("MEDICAMENTO: %s\n", ((Receita *)dado)->nomeMedicamento);
    printf("PACIENTE: %s\n", ((Receita *)dado)->nomePaciente);
    printf("INSTRUCOES: %s\n", ((Receita *)dado)->instrucoes);
    printf("MEDICO: %s\n", ((Receita *)dado)->nomeMedico);
    printf("- - - - - - - -\n");
}

/*
    Função que desaloca uma receita
    @param dado: ponteiro genérico para a receita a ser desalocada
*/

void desalocaReceita(void *dado)
{
    dado = (Receita *)dado;
    free(dado);
}
