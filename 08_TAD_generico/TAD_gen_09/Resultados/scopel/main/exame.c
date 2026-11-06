#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exame.h"

#define MAX_NOME 100
#define MAX_INSTRU 200

/*
    Estrutura do tipo Exame contendo os atributos necessários para a manipulação
*/
struct _Exame
{
    char DescricaoExame[MAX_NOME];
    char nomePaciente[MAX_NOME];
    char nomeMedico[MAX_NOME];
};

/*
    Função que cria uma Exame e retorna o seu endereço de memória
    @param DescricaoExame: nome do medicamento prescrito na Exame
    @param nomePaciente: nome do paciente para quem a Exame foi prescrita
    @param nomeMedico: nome do médico que prescreveu a Exame
    @param instrucoes: instruções para o uso do medicamento
    @return: endereço de memória da Exame criada
*/
Exame *criaExame(char *DescricaoExame, char *nomePaciente, char *nomeMedico)
{
    Exame *t = (Exame *)calloc(1, sizeof(Exame));
    strcpy(t->DescricaoExame, DescricaoExame);
    strcpy(t->nomeMedico, nomeMedico);
    strcpy(t->nomePaciente, nomePaciente);
    return t;
}

/*
    Função que lê os dados de uma Exame a partir da entrada padrão de acordo com a especificação
    @return: endereço de memória da Exame lida
*/
Exame *leExame()
{
    Exame r;
    scanf("%[^\n]\n%[^\n]\n%[^\n]\n", r.nomeMedico, r.nomePaciente, r.DescricaoExame);
    return criaExame(r.DescricaoExame, r.nomePaciente, r.nomeMedico);
}

/*
    Função que calcula o preço de impressão de uma Exame de acordo com a especificação
    @param dado: ponteiro genérico para a Exame a ser calculada
    @param precoCaractere: preço por caractere utilizado no cálculo
    @return: preço de impressão da Exame
*/
float calculaPrecoImpressaoExame(void *dado, float precoCaractere)
{
    int qtd_char = 0;

    qtd_char += strlen(((Exame *)dado)->DescricaoExame);
    qtd_char += strlen(((Exame *)dado)->nomeMedico);
    qtd_char += strlen(((Exame *)dado)->nomePaciente);

    return qtd_char * precoCaractere;
}

/*
    Função que imprime uma Exame de acordo com a especificação (veja os casos de teste)
    @param dado: ponteiro genérico para a Exame a ser impressa
*/
void imprimeExame(void *dado)
{
    printf("- - EXAME - -\n");
    printf("PACIENTE: %s\n", ((Exame *)dado)->nomePaciente);
    printf("SOLICITACAO: %s\n", ((Exame *)dado)->DescricaoExame);
    printf("MEDICO: %s\n", ((Exame *)dado)->nomeMedico);
    printf("- - - - - - -\n");
}

/*
    Função que desaloca uma Exame
    @param dado: ponteiro genérico para a Exame a ser desalocada
*/

void desalocaExame(void *dado)
{
    dado = (Exame *)dado;
    free(dado);
}
