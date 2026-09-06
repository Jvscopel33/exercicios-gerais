#include <stdio.h>
#include "filme.h"
#include "locadora.h"

// #define MAX_FILMES 100

// typedef struct Locadora {
//     tFilme filme[MAX_FILMES];
//     int numFilmes;
//     int lucro;
// } tLocadora;

/**
 * @brief Cria uma nova locadora.
 * @return Locadora criada.
 */
tLocadora criarLocadora()
{
    tLocadora l;
    l.numFilmes = 0;
    l.lucro = 0;
    return l;
}

/**
 * @brief Verifica se um filme está cadastrado na locadora.
 * @param locadora Locadora a ser consultada.
 * @param codigo Código do filme a ser verificado.
 * @return 1 se o filme está cadastrado, 0 caso contrário.
 */
int verificarFilmeCadastrado(tLocadora locadora, int codigo)
{
    for (int i = 0; i < locadora.numFilmes; i++)
    {
        if (ehMesmoCodigoFilme(locadora.filme[i], codigo))
        {
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Cadastra um filme na locadora, desde que ele não esteja cadastrado.
 * @param locadora Locadora a ser atualizada.
 * @param filme Filme a ser cadastrado.
 * @return Locadora atualizada.
 */
tLocadora cadastrarFilmeLocadora(tLocadora locadora, tFilme filme)
{
    if (!verificarFilmeCadastrado(locadora, obterCodigoFilme(filme)))
    {
        locadora.filme[locadora.numFilmes] = filme;
        printf("Filme cadastrado %d - ", obterCodigoFilme(locadora.filme[locadora.numFilmes]));
        imprimirNomeFilme(locadora.filme[locadora.numFilmes]);
        locadora.numFilmes++;
        printf("\n");
    }
    return locadora;
}

/**
 * @brief Lê o cadastro de um ou mais filmes a partir da entrada padrão e o cadastra na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerCadastroLocadora(tLocadora locadora)
{
    int cod;
    tFilme f;
    scanf(" %d,", &cod);
    f = leFilme(cod);
    cadastrarFilmeLocadora(locadora, f);
    return locadora;
}

/**
 * @brief Aluga um conjunto de filmes da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora alugarFilmesLocadora(tLocadora locadora, int *codigos, int quantidadeCodigos)
{
    for (int i; i < quantidadeCodigos; i++)
    {
        if (ehMesmoCodigoFilme(locadora.filme[i], codigos[i]))
        {
            locadora.filme[i] = alugarFilme(locadora.filme[i]);
            locadora.lucro += obterValorFilme(locadora.filme[i]);
        }
    }
    return locadora;
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerAluguelLocadora(tLocadora locadora)
{
    int cod[MAX_FILMES];
    char lix;
    int qtdcods = 0;
    do
    {
        scanf(" %d", &cod[qtdcods]);
        scanf("%c", &lix);
        qtdcods++;
    } while (lix != '#');
    locadora = alugarFilmesLocadora(locadora, cod, qtdcods);
    return locadora;
}

/**
 * @brief Devolve um conjunto de filmes alugados da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora devolverFilmesLocadora(tLocadora locadora, int *codigos, int quantidadeCodigos)
{
    for (int i; i < quantidadeCodigos; i++)
    {
        if (ehMesmoCodigoFilme(locadora.filme[i], codigos[i]))
        {
            locadora.filme[i] = devolverFilme(locadora.filme[i]);
        }
    }
    return locadora;
}

/**
 * @brief Lê a devolução de um conjunto de filmes a partir da entrada padrão e os devolve na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerDevolucaoLocadora(tLocadora locadora)
{
    int cod[MAX_FILMES];
    char lix;
    int qtdcods = 0;
    do
    {
        scanf(" %d", &cod[qtdcods]);
        scanf("%c", &lix);
        qtdcods++;
    } while (lix != '#');
    locadora = devolverFilmesLocadora(locadora, cod, qtdcods);
    return locadora;
}

/**
 * @brief Ordena os filmes da locadora por nome.
 * @param locadora Locadora a ser ordenada.
 * @return Locadora ordenada.
 */
tLocadora ordenarFilmesLocadora(tLocadora locadora)
{
    tFilme temp;
    for (int i = 0; i < locadora.numFilmes; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (compararNomesFilmes(locadora.filme[i], locadora.filme[j]) < 0)
            {
                temp = locadora.filme[j];
                locadora.filme[j] = locadora.filme[i];
                locadora.filme[i] = temp;
            }
        }
    }
}

/**
 * @brief Imprime o estoque da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarEstoqueLocadora(tLocadora locadora)
{
    printf("~ESTOQUE~\n");
    for (int i = 0; i < locadora.numFilmes; i++)
    {
        printf("%d - ", obterCodigoFilme(locadora.filme[i]));
        imprimirNomeFilme(locadora.filme[i]);
        printf("Fitas em estoque: %d\n", obterQtdEstoqueFilme(locadora.filme[i]));
    }
}

/**
 * @brief Imprime o lucro da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarLucroLocadora(tLocadora locadora)
{
    printf("Lucro total R$%d", locadora.lucro);
}
