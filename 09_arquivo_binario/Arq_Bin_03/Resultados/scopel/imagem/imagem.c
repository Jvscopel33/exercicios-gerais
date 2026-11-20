#include <stdio.h>
#include <stdlib.h>

#include "imagem.h"

/**
 * @brief Estrutura para representar uma imagem.
 */
struct tImagem
{
    void *data;
    int colunas;
    int linhas;
    Tipo tipo;
    size_t totaldeBytes;
};

/**
 * @brief Função para ler uma imagem de um arquivo binário e aloca-la na memória.
 * A função também armazena o número de bytes lidos na estrutura Imagem.
 * @param path O caminho para o arquivo de imagem.
 * @return Um ponteiro para a imagem lida. Se houver erro (de leitura ou alocação de memória), a função imprime uma mensagem de erro e termina o programa.
 */
Imagem *LerImagem(const char *caminho)
{
    FILE *f = fopen(caminho, "r");

    Imagem *i = (Imagem *)calloc(1, sizeof(Imagem));
    i->totaldeBytes = 0;
    int tipo;

    i->totaldeBytes += fread(&i->linhas, sizeof(int), 1, f);

    i->totaldeBytes += fread(&i->colunas, sizeof(int), 1, f);

    i->totaldeBytes += fread(&tipo, sizeof(int), 1, f);

    i->totaldeBytes *= sizeof(int);

    if (tipo == 0)
    {
        i->tipo = FLOAT;
    }
    else
    {
        i->tipo = INT;
    }
    if (i->tipo == INT)
    {
        size_t tamanhoPixel = sizeof(int);
        i->data = calloc(i->colunas * i->linhas, tamanhoPixel);
        fread(i->data, tamanhoPixel, i->colunas * i->linhas, f);
        i->totaldeBytes += tamanhoPixel;
    }
    else if (i->tipo == FLOAT)
    {
        size_t tamanhoPixel = sizeof(float);
        i->data = calloc(i->colunas * i->linhas, tamanhoPixel);
        fread(i->data, tamanhoPixel, i->colunas * i->linhas, f);
        i->totaldeBytes += tamanhoPixel;
    }

    fclose(f);
    return i;
}

/**
 * @brief Função para destruir uma imagem.
 * @param img A imagem a ser destruída.
 */
void DestruirImagem(Imagem *img)
{
    free(img->data);
    free(img);
}

/**
 * @brief Função para obter o número de bytes lidos de uma imagem.
 * @param img A imagem.
 * @return O número de bytes lidos.
 */
int ObterNumeroBytesLidos(Imagem *img)
{
    return img->totaldeBytes;
}

/**
 * @brief Função para imprimir uma imagem.
 * @param img A imagem.
 */
void ImprimirImagem(Imagem *img)
{
    for (int i = 0; i < img->linhas; i++)
    {

        for (int j = 0; j < img->colunas; j++)
        {
            int idx = i * img->colunas + j;

            if (img->tipo == INT)
            {
                printf("%d ", ((int *)img->data)[idx]);
            }
            else if (img->tipo == FLOAT)
            {
                printf("%.2f ", ((float *)img->data)[idx]);
            }
            if (j < img->colunas - 1)
            {
                printf("\n");
            }
        }
    }
}
