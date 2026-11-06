#include <stdio.h>
#include <stdlib.h>
#include "fila_imp.h"
#include "documento.h"

/*
    Estrutura do tipo FilaImp contendo os atributos necessários para a manipulação
*/
struct _FilaImp
{
    Documento **docs;
    int qtd_docs;
    float preco_total;
};

/*
    Função que cria uma fila de impressão e retorna o seu endereço de memória
    @return: endereço de memória da fila de impressão criada
*/
FilaImp *criaFilaImp()
{
    FilaImp *f = (FilaImp *)calloc(1, sizeof(FilaImp));
    f->docs = NULL;
    f->preco_total = 0;
    f->qtd_docs = 0;
    return f;
}

/*
    Função que desaloca uma fila de impressão
    @param f: ponteiro para a fila de impressão a ser desalocada
*/
void desalocaFilaImp(FilaImp *f)
{
    for (int i = 0; i < f->qtd_docs; i++)
    {
        desalocaDocumento(f->docs[i]);
    }
    free(f->docs);
    free(f);
}

/*
    Função que insere um documento na fila de impressão de acordo com a especificação
    @param f: ponteiro para a fila de impressão onde o documento será inserido
    @param dado: ponteiro genérico para o dado do documento a ser inserido
    @param imprime: ponteiro para a função de impressão do dado do documento genérico
    @param desaloca: ponteiro para a função de desalocação do dado do documento genérico
    @param calculaPreco: ponteiro para a função de cálculo do preço do dado do documento genérico
*/
void insereDocumentoFilaImp(FilaImp *f, void *dado, func_ptr_imprime imprime,
                            func_ptr_desaloca desaloca, func_ptr_calculaPreco calculaPreco)
{
    dado = criaDocumento(dado, imprime, desaloca, calculaPreco);
    f->docs = (Documento **)realloc(f->docs, (f->qtd_docs + 1) * sizeof(Documento *));
    f->docs[f->qtd_docs] = dado;
    f->qtd_docs++;
}

/*
    Função que retorna a quantidade de documentos na fila de impressão
    @param f: ponteiro para a fila de impressão
    @return: quantidade de documentos na fila de impressão
*/
int quantidadeDocumentosNaFilaImp(FilaImp *f)
{
    return f->qtd_docs;
}

/*
    Função que calcula o preço total de impressão de todos os documentos na fila de impressão
    @param f: ponteiro para a fila de impressão
    @param precoCaractere: preço por caractere utilizado no cálculo
    @return: preço total de impressão da fila
*/
float precoTotalImpressaoFilaImp(FilaImp *f, float precoCaractere)
{
    for (int i = 0; i < f->qtd_docs; i++)
    {
        f->preco_total += calculaPrecoImpressaoDocumento(f->docs[i], precoCaractere);
    }
    return f->preco_total;
}

/*
    Função que imprime toda a fila de impressão
    Obviamente, se não houver elementos na fila, a função não deve fazer nada.
    @param f: ponteiro para a fila de impressão
*/
void imprimeFilaImp(FilaImp *f)
{
    for (int i = 0; i < f->qtd_docs; i++)
    {
        imprimeDocumento(f->docs[i]);
    }
}
