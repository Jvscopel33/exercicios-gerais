#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imagem.h"
/**
 * @brief Enumeração para representar o tipo de dados da imagem.
 */
typedef enum
{
    FLOAT = 0,
    INT = 1
} Tipo;

/**
 * @brief Estrutura para representar uma imagem.
 */
struct tImagem
{
    void *data;
    Tipo type;
    int largura;
    int altura;
};

/**
 * @brief Função para obter a altura de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Altura da imagem.
 */
int ObterAltura(Imagem *img)
{
    return img->altura;
}

/**
 * @brief Função para obter a largura de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Largura da imagem.
 */
int ObterLargura(Imagem *img)
{
    return img->largura;
}

/**
 * @brief Função para obter o tipo de dados de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Tipo de dados da imagem.
 */
Tipo ObterTipoImagem(Imagem *img)
{
    return img->type;
}

/**
 * @brief Função para obter os dados de uma imagem.
 * Note que a imagem é uma matriz, mas os dados podem ser armazenados de forma linear (vetor).
 * @param img Ponteiro para a imagem.
 * @return Ponteiro para os dados da imagem.
 */
void *ObterDadosImagem(Imagem *img)
{
    return img->data;
}

/**
 * @brief Função para criar uma imagem.
 * @param altura Altura da imagem.
 * @param largura Largura da imagem.
 * @param tipo Tipo de dados da imagem.
 * @return Ponteiro para a imagem criada. Caso não seja possível criar a imagem, o programa é encerrado.
 */
Imagem *CriarImagem(int altura, int largura, Tipo tipo)
{
    Imagem *img = (Imagem *)calloc(1, sizeof(Imagem));
    img->altura = altura;
    img->largura = largura;
    img->type = tipo;
    img->data = NULL;
    return img;
}

/**
 * @brief Função para ler uma imagem, primeiro lendo a altura, largura e tipo de dados (tudo na mesma linha seperado por espaço). Em seguida, lê os dados da imagem.
 * @return Ponteiro para a imagem lida. (Crie a imagem com a função CriarImagem).
 */
Imagem *LerImagem()
{
    Imagem i;
    scanf()
    for(int i = 0; i < )
}

/**
 * @brief Função para imprimir uma imagem.
 * @param img Ponteiro para a imagem.
 */
void ImprimirImagem(Imagem *img);

/**
 * @brief Função para destruir uma imagem.
 * @param img Ponteiro para a imagem.
 */
void DestruirImagem(Imagem *img);
