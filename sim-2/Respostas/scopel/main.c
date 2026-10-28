#include <stdio.h>
#include <stdlib.h>
#include "datahora.h"
#include "estacionamento.h"
#include "proprietario.h"
#include "veiculo.h"

int main()
{
    char cmd;
    Estacionamento *e = criaEstacionamento();
    while (1)
    {
        scanf(" %c\n", &cmd);
        if (cmd == 'F')
        {
            break;
        }
        else if (cmd == 'E')
        {
            Veiculo *v = lerVeiculo();
            registraEntradaEstacionamento(e, v);
        }
        else if (cmd == 'S')
        {
            char placa[MAX_PLACA_VEIC];

            scanf(" %s\n", placa);
            DataHora *dataHora = lerDataHora();
            if (!registraSaidaEstacionamento(e, placa, dataHora))
            {
                liberaDataHora(dataHora);
            }
        }
    }
    printf("TOTAL ENTRADAS: %d\n", getTotalEntradasEstacionamento(e));
    printf("TOTAL SAIDAS: %d\n", getTotalSaidasEstacionamento(e));
    if (getTotalSaidasEstacionamento(e) > 0)
    {
        printf("PERMANENCIA MEDIA (MIN): %d\n", calculaPermanenciaTotalEstacionamento(e) / getTotalSaidasEstacionamento(e));
    }
    else
    {
        printf("PERMANENCIA MEDIA (MIN): -\n");
    }
    printf("FATURAMENTO (R$): %d\n", calculaFaturamentoEstacionamento(e));
    printf("VEICULOS NO PATIO: %d\n", getTotalNoPatioEstacionamento(e));
    printf("LISTA DE VEICULOS NO PATIO:\n");
    imprimeVeiculosNoPatioEstacionamento(e);
    liberaEstacionamento(e);
    return 0;
}