/**
 * @file data.h
 * @brief Biblioteca para manipulação de datas.
 *
 * Esta biblioteca contém funções para manipulação de datas, como verificação de datas válidas, impressão de datas e cálculo de diferença entre datas.
 */

#include <stdio.h>
#include "data.h"

/**
 * @brief Verifica se uma data é válida.
 *
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 * @return Retorna 1 se a data é válida e 0 caso contrário.
 */
int verificaDataValida(int dia, int mes, int ano)
{
    if (mes < 1 || mes > 12)
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
 * @brief Imprime uma data no formato DD/MM/AAAA.
 *
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeData(int dia, int mes, int ano)
{
    printf("%02d/%02d/%d", dia, mes, ano);
}

/**
 * @brief Imprime o nome do mês por extenso.
 *
 * @param mes Mês da data.
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
 * @brief Imprime uma data por extenso no formato "DD de NOME_DO_MES de AAAA".
 *
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeDataExtenso(int dia, int mes, int ano)
{
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %d\n", ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 *
 * @param ano Ano a ser verificado.
 * @return Retorna 1 se o ano é bissexto e 0 caso contrário.
 */
int verificaBissexto(int ano)
{
    if (!(ano % 4))
    {
        if (!(ano % 100))
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
    return 0;
}

/**
 * @brief Retorna o número de dias de um determinado mês.
 *
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return Retorna o número de dias do mês.
 */
int numeroDiasMes(int mes, int ano)
{
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
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
 * @return Retorna 1 se a primeira data é maior que a segunda, -1 se a primeira data é menor que a segunda e 0 se as datas são iguais.
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
 * @brief Calcula o número de dias até o início de um determinado mês.
 *
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return Retorna o número de dias até o início do mês.
 */
int calculaDiasAteMes(int mes, int ano)
{
    int qtdDias = 0;
    for (int i = 1; i < mes; i++)
    {
        qtdDias += numeroDiasMes(mes, ano);
    }
    return qtdDias;
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
 * @return Retorna o número de dias de diferença entre as datas.
 */
int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    int compData;
    int dia_ant, mes_ant, ano_ant;
    int dia_pos, mes_pos, ano_pos;
    int difDias = 0;
    compData = comparaData(dia1, mes1, ano1, dia2, mes2, ano2);
    if (compData == 1)
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
    for (int i = ano_ant; i < ano_pos; i++)
    {
        if (verificaBissexto(i))
        {
            difDias += 366;
        }
        else
        {
            difDias += 365;
        }
    }
    difDias += (calculaDiasAteMes(mes_pos, ano_pos) - calculaDiasAteMes(mes_ant, ano_pos));
    difDias += dia_pos - dia_ant;
    return difDias;
}

/**
 * @brief Imprime a próxima data no formato DD/MM/AAAA.
 *
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeProximaData(int dia, int mes, int ano)
{
    if (dia + 1 <= numeroDiasMes(mes, ano))
    {
        dia++;
    }
    else
    {
        if (mes + 1 <= 12)
        {
            dia = 1;
            mes++;
        }
        else
        {
            dia = 1;
            mes = 1;
            ano++;
        }
    }
    printf("%02d/%02d/%d", dia, mes, ano);
}
