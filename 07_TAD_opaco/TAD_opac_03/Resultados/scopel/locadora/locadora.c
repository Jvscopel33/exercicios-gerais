#include <stdio.h>
#include <stdlib.h>
#include "locadora.h"
#include "filme.h"

struct Locadora
{
    tFilme **filmes;
    int qtdFilmes;
    int lucro;
};

/**
 * @brief Cria uma nova instância de tLocadora e inicializa filme como NULL, numFilmes como 0 e lucro como 0.
 *
 * @return tLocadora* Ponteiro para a nova instância de tLocadora criada ou encerra o programa caso não haja memória suficiente.
 */
tLocadora *CriarLocadora()
{
    tLocadora *l = (tLocadora *)calloc(1, sizeof(tLocadora));
    if (l == NULL)
    {
        printf("DEU RUIM NA ALOCACAO\n");
        exit(1);
    }
    l->filmes = NULL;
    l->qtdFilmes = 0;
    l->lucro = 0;
    return l;
}

/**
 * @brief Destrói uma instância de tLocadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser destruída.
 */
void DestruirLocadora(tLocadora *locadora)
{
    for (int i = 0; i < locadora->qtdFilmes; i++)
    {
        DestruirFilme(locadora->filmes[i]);
    }
    free(locadora->filmes);
    free(locadora);
}

/**
 * @brief Verifica se um filme está cadastrado na locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser verificada.
 * @param codigo Código do filme a ser verificado.
 * @return int 1 se o filme está cadastrado, 0 caso contrário.
 */
int VerificarFilmeCadastrado(tLocadora *locadora, int codigo)
{
    for (int i = 0; i < locadora->qtdFilmes; i++)
    {

        if (EhMesmoCodigoFilme(locadora->filmes[i], codigo))
        {
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Cadastra um novo filme na locadora caso ele não esteja cadastrado.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param filme Ponteiro para o filme a ser cadastrado.
 */

void CadastrarFilmeLocadora(tLocadora *locadora, tFilme *filme)
{

    locadora->filmes = (tFilme **)realloc(locadora->filmes, (locadora->qtdFilmes + 1) * sizeof(tFilme *));
    locadora->filmes[locadora->qtdFilmes] = filme;
    locadora->qtdFilmes++;
    printf("Filme cadastrado %d - ", ObterCodigoFilme(filme));
    ImprimirNomeFilme(filme);
    printf("\n");
}

/**
 * @brief Lê os dados de cadastro de um filme e o cadastra na locadora.
 *
 * @param Locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerCadastroLocadora(tLocadora *Locadora)
{
    int cod;
    tFilme *f = CriarFilme();
    scanf(" %d,", &cod);
    LeFilme(f, cod);
    if (!VerificarFilmeCadastrado(Locadora, cod))
    {
        CadastrarFilmeLocadora(Locadora, f);
    }
    else
    {
        DestruirFilme(f);
    }
}

/**
 * @brief Aluga um ou mais filmes da locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Número de códigos de filmes a serem alugados.
 */
void AlugarFilmesLocadora(tLocadora *locadora, int *codigos, int quantidadeCodigos)
{

    for (int i = 0; i < quantidadeCodigos; i++)
    {
        int encontrou = 0;
        for (int j = 0; j < locadora->qtdFilmes; j++)
        {
            if (VerificarFilmeCadastrado(locadora, codigos[i]))
            {
                encontrou++;
                if (ObterQtdEstoqueFilme(locadora->filmes[j]) < ObterQtdAlugadaFilme(locadora->filmes[j]))
                {
                    AlugarFilme(locadora->filmes[j]);
                }
            }
        }
        if (!encontrou)
        {
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }
    }
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerAluguelLocadora(tLocadora *locadora)
{
    int *codigos = NULL;
    int cod = 0;
    int qtdcodigos = 0;
    while (scanf(" %d\n", &cod) == 1)
    {
        codigos = (int *)realloc(codigos, (qtdcodigos + 1) * sizeof(int));
        codigos[qtdcodigos] = cod;
        qtdcodigos++;
    }
    getchar();
    AlugarFilmesLocadora(locadora, codigos, qtdcodigos);
    free(codigos);
}

/**
 * @brief Devolve um ou mais filmes alugados da locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Número de códigos de filmes a serem devolvidos.
 */
void DevolverFilmesLocadora(tLocadora *locadora, int *codigos, int quantidadeCodigos)
{
    for (int j = 0; j < locadora->qtdFilmes; j++)
    {
        for (int i = 0; i < quantidadeCodigos; i++)
        {
            if (EhMesmoCodigoFilme(locadora->filmes[j], codigos[i]))
            {
                if (ObterQtdEstoqueFilme(locadora->filmes[j]) > 0)
                {
                    DevolverFilme(locadora->filmes[j]);
                    locadora->lucro += ObterValorFilme(locadora->filmes[j]);
                }
            }
        }
    }
}

/**
 * @brief Lê os dados de devolução de um ou mais filmes e os devolve na locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerDevolucaoLocadora(tLocadora *locadora)
{
    int *codigos = NULL;
    int cod;
    int qtdcodigos = 0;
    while (scanf(" %d\n", &cod) == 1)
    {
        codigos = (int *)realloc(codigos, (qtdcodigos + 1) * sizeof(int));
        codigos[qtdcodigos] = cod;
        qtdcodigos++;
    }
    DevolverFilmesLocadora(locadora, codigos, qtdcodigos);
    free(codigos);
}

/**
 * @brief Ordena os filmes cadastrados na locadora por ordem alfabética.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void OrdenarFilmesLocadora(tLocadora *locadora)
{
    for (int i = 0; i < locadora->qtdFilmes; i++)
    {
        for (int j = 0; j < locadora->qtdFilmes - 1 - i; j++)
        {
            tFilme *temp;

            if (CompararNomesFilmes(locadora->filmes[j], locadora->filmes[j + 1]) > 0)
            {
                temp = locadora->filmes[j + 1];
                locadora->filmes[j + 1] = locadora->filmes[j];
                locadora->filmes[j] = temp;
            }
        }
    }
}

/**
 * @brief Consulta o estoque de filmes da locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarEstoqueLocadora(tLocadora *locadora)
{
    printf("~ESTOQUE~\n");
    for (int i = 0; i < locadora->qtdFilmes; i++)
    {
        if (ObterQtdEstoqueFilme(locadora->filmes[i]) > 0)
        {
            printf("%d - ", ObterCodigoFilme(locadora->filmes[i]));
            ImprimirNomeFilme(locadora->filmes[i]);
            printf(" Fitas em estoque: %d\n", ObterQtdEstoqueFilme(locadora->filmes[i]));
        }
    }
}

/**
 * @brief Consulta o lucro da locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarLucroLocadora(tLocadora *locadora)
{
    if (locadora->lucro > 0)
    {
        printf("Lucro total R$%d\n", locadora->lucro);
    }
}
