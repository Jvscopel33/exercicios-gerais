#include <stdio.h>
#include <stdlib.h>
#include "data.h"

struct Data
{
    int dia, mes, ano;
};

/**
 * @brief Aloca dinamicamente uma estrutura do tipo tData, e a retorna.
 * Os campos dessa estrutura devem ser preenchidos inicialmente com -1.
 *
 * @return tData - Data "Vazia"
 */
tData *CriaData()
{
    tData *d = (tData *)calloc(1, sizeof(tData));
    d->dia = -1;
    d->mes = -1;
    d->ano = -1;
    return d;
}

/**
 * @brief Lê o dia, mês e ano e armazena em uma estrutura tData alocada dinamicamente.
 *
 * @param data - Ponteiro para a estrutura onde os dados serão armazenados. Lembre-se: Não pode ter valor NULL.
 */

void LeData(tData *data)
{
    if (data != NULL)
    {
        scanf(" %d/%d/%d\n", &data->dia, &data->mes, &data->ano);
    }
}

/**
 * @brief Libera a memória alocada dinamicamente para uma estrutura do tipo tData, passada como parâmetro
 * @param data - Ponteiro para a estrutura onde os dados estão armazenados.
 */

void LiberaData(tData *data)
{
    free(data);
}

/**
 * @brief Verifica se uma data é válida.
 *
 * @param data Data a ser verificada.
 * @return int 1 se a data é válida, 0 caso contrário.
 */
int VerificaDataValida(tData *data)
{
    if (data->dia <= NumeroDiasMes(data) && data->dia > 0)
    {
        if (data->mes <= 12 && data->mes > 0)
        {
            if (data->ano > 0)
            {
                return 1;
            }
        }
    }
    return 0;
}

/**
 * @brief Imprime o mês de uma data em formato extenso.
 *
 * @param data Data cujo mês será impresso em formato extenso.
 */

void ImprimeMesExtenso(tData *data)
{
    switch (data->mes)
    {
    case 1:
        printf("Janeiro");
        break;
    case 2:
        printf("Fevereiro");
        break;
    case 3:
        printf("Marco");
        break;
    case 4:
        printf("Abril");
        break;
    case 5:
        printf("Maio");
        break;
    case 6:
        printf("Junho");
        break;
    case 7:
        printf("Julho");
        break;
    case 8:
        printf("Agosto");
        break;
    case 9:
        printf("Setembro");
        break;
    case 10:
        printf("Outubro");
        break;
    case 11:
        printf("Novembro");
        break;
    case 12:
        printf("Dezembro");
        break;
    }
}

/**
 * @brief Imprime uma data em formato extenso.
 *
 * @param data Data a ser impressa em formato extenso.
 */

void ImprimeDataExtenso(tData *data)
{
    printf("%02d de ", data->dia);
    ImprimeMesExtenso(data);
    printf(" de %d\n", data->ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 *
 * @param data Data cujo ano será verificado.
 * @return int 1 se o ano é bissexto, 0 caso contrário.
 */

int VerificaBissexto(tData *data)
{
    if (!(data->ano % 4))
    {
        if (!(data->ano % 100))
        {
            if (!(data->ano % 400))
            {
                return 1;
            }
            return 0;
        }
        return 1;
    }
    return 0;
}

/**
 * @brief Retorna o número de dias de um determinado mês.
 *
 * @param data Data cujo mês terá o número de dias retornado.
 * @return int Número de dias do mês da data.
 */

int NumeroDiasMes(tData *data)
{

    if (data->mes == 1 || data->mes == 3 || data->mes == 5 || data->mes == 7 || data->mes == 8 || data->mes == 10 || data->mes == 12)
    {
        return 31;
    }
    else if (data->mes == 2)
    {
        if (VerificaBissexto(data))
        {
            return 29;
        }
        return 28;
    }
    return 30;
}

/**
 * @brief Compara duas datas.
 *
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int 1 se data1 é maior que data2, -1 se data1 é menor que data2, 0 se as datas são iguais.
 * A data ser maior significa que ela é mais recente.
 */

int ComparaData(tData *data1, tData *data2)
{
    if (data1->ano > data2->ano)
    {
        return 1;
    }
    if (data1->ano == data2->ano)
    {
        if (data1->mes > data2->mes)
        {
            return 1;
        }
        if (data1->mes == data2->mes)
        {
            if (data1->dia > data2->dia)
            {
                return 1;
            }
            if (data1->dia == data2->dia)
            {
                return 0;
            }
        }
    }
    return -1;
}

/**
 * @brief Calcula o número de dias até o início do mês de uma determinada data.
 *
 * @param data Data cujo número de dias até o início do mês será calculado.
 * @return int Número de dias até o início do mês da data.
 */
int CalculaDiasAteMes(tData *data)
{
    int dias = 0;
    tData *d = CriaData();
    d->ano = data->ano;
    d->dia = data->dia;
    d->mes = 1;
    for (int i = 1; i < data->mes; i++)
    {
        dias += NumeroDiasMes(d);
        d->mes++;
    }
    LiberaData(d);
    return dias;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 *
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int Número de dias entre as duas datas.
 */
int CalculaDiferencaDias(tData *data1, tData *data2)
{
    int diffDias = 0;
    tData *dataMaior;
    tData *dataMenor;

    if (ComparaData(data1, data2) == 1)
    {
        dataMaior = data1;
        dataMenor = data2;
    }
    else
    {
        dataMaior = data2;
        dataMenor = data1;
    }
    tData *temp = CriaData();
    temp->ano = dataMenor->ano;
    temp->dia = dataMenor->dia;
    temp->mes = dataMenor->mes;
    for (int i = dataMenor->ano; i < dataMaior->ano; i++)
    {
        if (VerificaBissexto(temp))
        {
            diffDias += 366;
        }
        else
        {
            diffDias += 365;
        }
        temp->ano++;
    }
    diffDias += dataMaior->dia - dataMenor->dia;
    diffDias += (CalculaDiasAteMes(dataMaior) - CalculaDiasAteMes(dataMenor));
    LiberaData(temp);
    return diffDias;
}
