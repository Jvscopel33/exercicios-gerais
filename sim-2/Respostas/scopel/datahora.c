#include <stdio.h>
#include <stdlib.h>
#include "datahora.h"

struct DataHora
{
    int dia, mes, ano;
    int hora, minuto;
};

int verificaAnoBissexto(DataHora *d)
{
    if (!(d->ano % 4))
    {
        if (!(d->ano % 100))
        {
            if (!(d->ano % 400))
            {
                return 1;
            }
            return 0;
        }
        return 1;
    }
    return 0;
}

int numerosDiasMes(DataHora *d)
{
    if (d->mes == 1 || d->mes == 3 || d->mes == 5 || d->mes == 7 || d->mes == 8 || d->mes == 10 || d->mes == 12)
    {
        return 31;
    }
    else if (d->mes == 2)
    {

        if (verificaAnoBissexto(d))
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
    return 30;
}

long long calculaMinutos(DataHora *d)
{
    long long totalDias = 0;
    DataHora *temp = criaDataHora(1, 1, 1, d->hora, d->minuto);
    for (int i = 1; i < d->ano; i++)
    {
        totalDias += verificaAnoBissexto(temp) ? 366 : 365;
        temp->ano++;
    }
    for (int i = 1; i < d->mes; i++)
    {
        totalDias += numerosDiasMes(temp);
        temp->mes++;
    }
    totalDias += d->dia - 1;
    liberaDataHora(temp);
    return totalDias * 1440LL + d->hora * 60 + d->minuto;
}
/**
 * @brief   Cria uma data/hora a partir dos valores informados.
 *
 * @param dia     [entrada]  Dia do mês, inteiro em [1, 31] (válido para o mês/ano).
 * @param mes     [entrada]  Mês, inteiro em [1, 12].
 * @param ano     [entrada]  Ano com 4 dígitos (ex.: 2026), inteiro >= 1.
 * @param hora    [entrada]  Hora do dia, inteiro em [0, 23].
 * @param minuto  [entrada]  Minuto, inteiro em [0, 59].
 *
 * @return  Ponteiro para o DataHora criado (alocado dinamicamente);
 *          NULL se a alocação de memória falhar.
 *
 * @pre     Os valores formam uma data/hora válida (a função NÃO valida).
 * @post    O chamador é dono do DataHora retornado e deve liberá-lo com
 *          liberaDataHora() (ou transferir a posse para outro TAD que o libere).
 */
DataHora *criaDataHora(int dia, int mes, int ano, int hora, int minuto)
{
    DataHora *d = (DataHora *)calloc(1, sizeof(DataHora));
    d->ano = ano;
    d->mes = mes;
    d->dia = dia;
    d->hora = hora;
    d->minuto = minuto;
    return d;
}

/**
 * @brief   Lê uma data/hora da entrada padrão e cria o DataHora correspondente.
 *
 * Lê UMA linha no formato "DD/MM/AAAA HH:MM" (data, um espaço, horário), por
 * exemplo "27/10/2026 08:05", consumindo também a quebra de linha final.
 *
 * @return  Ponteiro para o DataHora lido (mesmas regras de posse de criaDataHora()).
 *
 * @pre     A próxima linha da entrada padrão contém uma data/hora válida no formato
 *          acima.
 */
DataHora *lerDataHora()
{
    struct DataHora d;
    scanf(" %d/%d/%d %d:%d\n", &d.dia, &d.mes, &d.ano, &d.hora, &d.minuto);
    DataHora *data = criaDataHora(d.dia, d.mes, d.ano, d.hora, d.minuto);
    return data;
}

/**
 * @brief   Calcula quantos minutos se passaram entre duas datas/horas.
 *
 * O cálculo considera o calendário real:
 *   - meses com 31 dias: 1, 3, 5, 7, 8, 10, 12; com 30 dias: 4, 6, 9, 11;
 *   - fevereiro tem 29 dias em ano bissexto e 28 nos demais;
 *   - um ano é bissexto se for divisível por 400, ou se for divisível por 4 e NÃO
 *     for divisível por 100 (ex.: 2028 e 2000 são bissextos; 2026 e 2100 não são);
 *   - cada dia tem 24 * 60 = 1440 minutos.
 * Exemplos:
 *   inicio = 27/10/2026 08:50, fim = 27/10/2026 10:05  ->  75
 *   inicio = 27/10/2026 23:30, fim = 28/10/2026 00:10  ->  40
 *   inicio = 28/02/2028 12:00, fim = 01/03/2028 12:00  ->  2880 (2028 é bissexto)
 *
 * @param inicio  [entrada]  Data/hora inicial (não-nula).
 * @param fim     [entrada]  Data/hora final (não-nula).
 *
 * @return  Diferença em minutos (fim - inicio). É >= 0 sempre que fim não for
 *          anterior a inicio.
 *
 * @pre     inicio != NULL e fim != NULL.
 * @note    Nenhuma das duas datas/horas é modificada ou liberada.
 */
int diferencaMinutosDataHora(DataHora *inicio, DataHora *fim)
{
    long long minutosTotaisInicio = calculaMinutos(inicio);
    long long minutosTotaisFim = calculaMinutos(fim);

    return ((int)(minutosTotaisFim - minutosTotaisInicio));
}

/**
 * @brief   Imprime a data/hora na saída padrão no formato "DD/MM/AAAA HH:MM".
 *
 * Dia, mês, hora e minuto são impressos SEMPRE com dois dígitos e o ano com quatro
 * (zeros à esquerda quando necessário). Ex.: "05/03/2027 08:05". Há exatamente um
 * espaço entre a data e o horário. NÃO imprime quebra de linha nem espaços
 * antes/depois.
 *
 * @param dh  [entrada]  Data/hora a imprimir (não-nula).
 * @pre     dh != NULL.
 */
void imprimeDataHora(DataHora *dh)
{
    printf("%02d/%02d/%d %02d:%02d\n", dh->dia, dh->mes, dh->ano, dh->hora, dh->minuto);
}

/**
 * @brief   Libera a memória alocada para uma data/hora.
 *
 * @param dh  [entrada]  Data/hora a liberar.
 * @post    A memória apontada por dh é liberada; o ponteiro não deve mais ser usado.
 */

void liberaDataHora(DataHora *dh)
{
    free(dh);
}
