/**
 * @file data.h
 * @brief Biblioteca para manipulação de datas.
 *
 * Esta biblioteca contém funções para verificar a validade de uma data, imprimir uma data por extenso,
 * verificar se um ano é bissexto, calcular o número de dias de um mês, comparar duas datas e calcular a
 * diferença em dias entre duas datas.
 *
 */

#include <stdio.h>
#include "data.h"

/**
 * @brief Verifica se uma data é válida.
 *
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 * @return int Retorna 1 se a data é válida e 0 caso contrário.
 */
int verificaDataValida(int dia, int mes, int ano)
{
    if (mes > 12 || mes < 1)
    {
        return 0;
    }
    if (dia > numeroDiasMes(mes, ano))
    {
        return 0;
    }
    return 1;
}

/**
 * @brief Imprime o nome do mês por extenso.
 *
 * @param mes Mês a ser impresso.
 */
void imprimeMesExtenso(int mes)
{
    switch (mes)
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
 * @brief Imprime a data por extenso.
 *
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeDataExtenso(int dia, int mes, int ano)
{
    printf("%d de", dia);
    imprimeMesExtenso(mes);
    printf(" de %d", ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 *
 * @param ano Ano a ser verificado.
 * @return int Retorna 1 se o ano é bissexto e 0 caso contrário.
 */
int verificaBissexto(int ano)
{
    if (!(ano % 4))
    {

        if (ano % 100 == 0)
        {
            if (!(ano % 400))
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

/**
 * @brief Calcula o número de dias de um mês.
 *
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return int Retorna o número de dias do mês.
 */
int numeroDiasMes(int mes, int ano)
{
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 11 || mes == 12)
    {
        return 31;
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        return 30;
    }
    else if (mes == 2 && verificaBissexto(ano))
    {
        return 29;
    }
    else
    {
        return 28;
    }
}

/**
 * @brief Compara duas datas.
 *
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return int Retorna 1 se a primeira data é maior que a segunda, -1 se a primeira data é menor que a segunda
 * e 0 se as datas são iguais.
 * A data ser "maior" significa que ela está mais no futuro.
 */
int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    if (ano1 > ano2)
    {
        return 1;
    }
    else if (ano1 < ano2)
    {
        return -1;
    }
    else if (ano1 == ano2)
    {
        if (mes1 > mes2)
        {
            return 1;
        }
        else if (mes1 < mes2)
        {
            return -1;
        }
        else if (mes1 == mes2)
        {
            if (dia1 > dia2)
            {
                return 1;
            }
            else if (dia1 < dia2)
            {
                return -1;
            }
        }
    }
    return 0;
}

/**
 * @brief Calcula o número de dias até o mês.
 *
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return int Retorna o número de dias até o mês.
 */
int calculaDiasAteMes(int mes, int ano)
{
    int dias = 0;
    for (int i = 1; i < mes; i++)
    {
        dias += numeroDiasMes(i, ano);
    }
    return dias;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 *
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return int Retorna o número de dias de diferença entre as datas.
 */
int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    int dia_ant, mes_ant, ano_ant;
    int dia_pos, mes_pos, ano_pos;
    int difdias = 0;
    if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 0)
    {
        return 0;
    }
    if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 1)
    {
        dia_ant = dia2;
        mes_ant = mes2;
        ano_ant = ano2;
        dia_pos = dia1;
        mes_pos = mes1;
        ano_pos = ano1;
    }
    else
    {

        dia_ant = dia1;
        mes_ant = mes1;
        ano_ant = ano1;
        dia_pos = dia2;
        mes_pos = mes2;
        ano_pos = ano2;
    }
    // Diferença de ano
    for (int i = ano_ant; i < ano_pos; i++)
    {
        if (verificaBissexto(i))
        {
            difdias += 366;
        }
        else
        {
            difdias += 365;
        }
    }
    // diferença de meses
    difdias += (calculaDiasAteMes(mes_pos, ano_pos) - calculaDiasAteMes(mes_ant, ano_ant));
    difdias += dia_pos - dia_ant;
    return difdias;
}
