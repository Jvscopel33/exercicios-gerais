#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "documento.h"
#include "fila_imp.h"
#include "receita.h"
#include "encaminhamento.h"
#include "exame.h"

int main()
{
    FilaImp *f = criaFilaImp();
    Exame *e;
    Receita *r;
    Encaminhamento *en;
    float precoImprecao;
    scanf(" %f\n", &precoImprecao);
    char cmd[50];
    while (1)
    {
        scanf(" %s\n", cmd);
        if (!strcmp(cmd, "FIM"))
        {
            break;
        }
        if (!strcmp(cmd, "RECEITA"))
        {
            r = leReceita();
            insereDocumentoFilaImp(f, r, imprimeReceita, desalocaReceita, calculaPrecoImpressaoReceita);
        }
        else if (!strcmp(cmd, "ENCAMINHAMENTO"))
        {
            en = leEncaminhamento();
            insereDocumentoFilaImp(f, en, imprimeEncaminhamento, desalocaEncaminhamento, calculaPrecoImpressaoEncaminhamento);
        }
        else if (!strcmp(cmd, "EXAME"))
        {
            e = leExame();
            insereDocumentoFilaImp(f, e, imprimeExame, desalocaExame, calculaPrecoImpressaoExame);
        }
        else if (!strcmp(cmd, "QUANTIDADE"))
        {
            printf("- QUANTIDADE DE DOCUMENTOS NA FILA: %d\n", quantidadeDocumentosNaFilaImp(f));
        }
        else if (!strcmp(cmd, "PRECO"))
        {
            printf("- PRECO TOTAL DA FILA: R$ %.2f\n", precoTotalImpressaoFilaImp(f, precoImprecao));
        }
        else if (!strcmp(cmd, "IMPRIME"))
        {
            imprimeFilaImp(f);
        }
    }
    desalocaFilaImp(f);
    return 0;
}