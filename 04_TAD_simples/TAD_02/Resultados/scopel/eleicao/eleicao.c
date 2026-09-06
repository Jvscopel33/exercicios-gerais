#include <stdio.h>
#include "candidato.h"
#include "eleitor.h"
#include "eleicao.h"
#include <stdlib.h>

// #define MAX_CANDIDATOS_POR_CARGO 3
// #define MAX_ELEITORES 10

// typedef struct {
//     tCandidato presidentes[MAX_CANDIDATOS_POR_CARGO];
//     int totalPresidentes;

//     tCandidato governadores[MAX_CANDIDATOS_POR_CARGO];
//     int totalGovernadores;

//     int votosBrancosPresidente;
//     int votosNulosPresidente;

//     int votosBrancosGovernador;
//     int votosNulosGovernador;

//     tEleitor eleitores[MAX_ELEITORES];
//     int totalEleitores;

// } tEleicao;

/**
 * @brief Inicializa uma eleição com valores padrão (zerando os votos invalidos).
 * Ainda nessa função, é lido a quantidade de candidatos e os candidatos são lidos e armazenados.
 * @return Eleição inicializada.
 */
tEleicao InicializaEleicao()
{
    tEleicao e;
    tCandidato c;
    int n;
    e.votosBrancosGovernador = 0;
    e.votosBrancosPresidente = 0;
    e.totalEleitores = 0;
    e.votosNulosGovernador = 0;
    e.votosNulosPresidente = 0;
    e.totalPresidentes = 0;
    e.totalGovernadores = 0;
    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
    {
        c = LeCandidato();
        if (ObtemCargo(c) == 'P')
        {
            if (e.totalPresidentes >= MAX_CANDIDATOS_POR_CARGO)
            {
                printf("ELEICAO ANULADA\n");
                return e;
            }
            e.presidentes[e.totalPresidentes] = c;
            e.totalPresidentes++;
        }
        else if (ObtemCargo(c) == 'G')
        {
            if (e.totalGovernadores >= MAX_CANDIDATOS_POR_CARGO)
            {
                printf("ELEICAO ANULADA\n");
                exit(1);
                return e;
            }
            e.governadores[e.totalGovernadores] = c;
            e.totalGovernadores++;
        }
    }
    return e;
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada.
 * @return Eleição com os resultados da votação.
 */
tEleicao RealizaEleicao(tEleicao eleicao)
{
    int encontrou = 0;
    scanf(" %d\n", &eleicao.totalEleitores);
    if (eleicao.totalEleitores > 10)
    {
        printf("ELEICAO ANULADA\n");
        exit(1);
    }
    for (int i = 0; i < eleicao.totalEleitores; i++)
    {
        eleicao.eleitores[i] = LeEleitor();
    }
    for (int i = 0; i < eleicao.totalEleitores; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (EhMesmoEleitor(eleicao.eleitores[i], eleicao.eleitores[j]))
            {
                printf("ELEICAO ANULADA\n");
                exit(1);
            }
        }
    }
    encontrou = 0;
    for (int i = 0; i < eleicao.totalEleitores; i++)
    {
        if (ObtemVotoPresidente(eleicao.eleitores[i]) == 0)
        {
            eleicao.votosBrancosPresidente++;
        }
        else
        {
            encontrou = 0;
            for (int j = 0; j < eleicao.totalPresidentes; j++)
            {
                if (VerificaIdCandidato(eleicao.presidentes[j], ObtemVotoPresidente(eleicao.eleitores[i])))
                {
                    eleicao.presidentes[j] = IncrementaVotoCandidato(eleicao.presidentes[j]);
                    encontrou++;
                    break;
                }
            }
            if (!encontrou)
            {
                eleicao.votosNulosPresidente++;
            }
        }
        if (ObtemVotoGovernador(eleicao.eleitores[i]) == 0)
        {
            eleicao.votosBrancosGovernador++;
        }
        else
        {
            encontrou = 0;
            for (int j = 0; j < eleicao.totalGovernadores; j++)
            {

                if (VerificaIdCandidato(eleicao.governadores[j], ObtemVotoGovernador(eleicao.eleitores[i])))
                {
                    eleicao.governadores[j] = IncrementaVotoCandidato(eleicao.governadores[j]);
                    encontrou++;
                    break;
                }
            }
            if (!encontrou)
            {
                eleicao.votosNulosGovernador++;
            }
        }
    }
    return eleicao;
}

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */

void ImprimeResultadoEleicao(tEleicao eleicao)
{
    int win = 0;
    int empate = 0;
    printf("- PRESIDENTE ELEITO: ");
    for (int i = 1; i < eleicao.totalPresidentes; i++)
    {
        if (ObtemVotos(eleicao.presidentes[i]) > ObtemVotos(eleicao.presidentes[win]))
        {
            win = i;
            empate = 0;
        }
        else if (ObtemVotos(eleicao.presidentes[i]) == ObtemVotos(eleicao.presidentes[win]) && !EhMesmoCandidato(eleicao.presidentes[i], eleicao.presidentes[win]))
        {
            empate++;
        }
    }
    if (empate)
    {
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    }
    else if ((eleicao.votosBrancosPresidente + eleicao.votosNulosPresidente) >= ObtemVotos(eleicao.presidentes[win]))
    {
        printf("SEM DECISAO\n");
    }
    else
    {
        ImprimeCandidato(eleicao.presidentes[win], CalculaPercentualVotos(eleicao.presidentes[win], eleicao.totalEleitores));
    }
    printf("- GOVERNADOR ELEITO: ");
    empate = 0;
    win = 0;
    for (int i = 1; i < eleicao.totalGovernadores; i++)
    {
        if (ObtemVotos(eleicao.governadores[i]) > ObtemVotos(eleicao.governadores[win]))
        {
            win = i;
            empate = 0;
        }
        else if (ObtemVotos(eleicao.governadores[i]) == ObtemVotos(eleicao.governadores[win]) && !EhMesmoCandidato(eleicao.governadores[i], eleicao.governadores[win]))
        {
            empate++;
        }
    }
    if (empate)
    {
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    }
    else if ((eleicao.votosBrancosGovernador + eleicao.votosNulosGovernador) >= ObtemVotos(eleicao.governadores[win]))
    {
        printf("SEM DECISAO\n");
    }
    else
    {
        ImprimeCandidato(eleicao.governadores[win], CalculaPercentualVotos(eleicao.governadores[win], eleicao.totalEleitores));
    }
    printf("- NULOS E BRANCOS: %d, %d", (eleicao.votosNulosGovernador + eleicao.votosNulosPresidente), (eleicao.votosBrancosGovernador + eleicao.votosBrancosPresidente));
}
