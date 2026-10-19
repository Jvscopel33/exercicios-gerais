#include <stdio.h>
#include <stdlib.h>
#include "eleicao.h"
#include "candidato.h"
#include "eleitor.h"

#define MAX_CANDIDATOS_POR_CARGO 3
#define MAX_ELEITORES 10

// typedef struct {
//     tCandidato** presidentes;
//     int totalPresidentes;

//     tCandidato** governadores;
//     int totalGovernadores;

//     int votosBrancosPresidente;
//     int votosNulosPresidente;

//     int votosBrancosGovernador;
//     int votosNulosGovernador;

//     tEleitor** eleitores;
//     int totalEleitores;

// } tEleicao;

/**
 * @brief Inicializa uma eleição com valores padrão (zerando as variáveis que armazenam votos).
 * Ainda nessa função, é lido a quantidade de candidatos e os candidatos são lidos e armazenados
 * A memória necessária para os vetores "presidentes", "governadores" deve ser alocada aqui.
 * Demais ponteiros devem ser inicializado com NULL.
 * @return Eleição inicializada.
 */
tEleicao *InicializaEleicao()
{
    int totalCandidatos;

    tEleicao *e = calloc(1, sizeof(tEleicao));

    e->presidentes = (tCandidato **)calloc(MAX_CANDIDATOS_POR_CARGO, sizeof(tCandidato *));
    e->governadores = (tCandidato **)calloc(MAX_CANDIDATOS_POR_CARGO, sizeof(tCandidato *));

    scanf(" %d\n", &totalCandidatos);
    for (int i = 0; i < totalCandidatos; i++)
    {
        tCandidato *temp = calloc(1, sizeof(tCandidato));
        LeCandidato(temp);
        if (ObtemCargo(temp) == 'P')
        {
            if (e->totalPresidentes < MAX_CANDIDATOS_POR_CARGO)
            {
                e->presidentes[e->totalPresidentes] = temp;
                e->totalPresidentes++;
            }
        }

        else if (ObtemCargo(temp) == 'G')
        {
            if (e->totalGovernadores < MAX_CANDIDATOS_POR_CARGO)
            {
                e->governadores[e->totalGovernadores] = temp;
                e->totalGovernadores++;
            }
        }
        ApagaCandidato(temp);
    }
    e->eleitores = NULL;
    e->totalEleitores = 0;
    e->totalGovernadores = 0;
    e->totalPresidentes = 0;
    e->votosBrancosGovernador = 0;
    e->votosBrancosPresidente = 0;
    e->votosNulosGovernador = 0;
    e->votosNulosPresidente = 0;
    return e;
}

void ApagaEleicao(tEleicao *eleicao)
{
    for (int i = 0; i < MAX_CANDIDATOS_POR_CARGO; i++)
    {
        ApagaCandidato(eleicao->presidentes[i]);
        ApagaCandidato(eleicao->governadores[i]);
    }
    free(eleicao->governadores);
    free(eleicao->presidentes);

    for (int i = 0; i < MAX_ELEITORES; i++)
    {
        ApagaEleitor(eleicao->eleitores[i]);
    }
    free(eleicao->eleitores);
    free(eleicao);
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada.
 */
void RealizaEleicao(tEleicao *eleicao)
{
    int encontrou = 0;
    scanf(" %d\n", &eleicao->totalEleitores);
    if (eleicao->totalEleitores > 10)
    {
        printf("ELEICAO ANULADA\n");
        exit(1);
    }
    for (int i = 0; i < eleicao->totalEleitores; i++)
    {
        if (i < MAX_ELEITORES)
        {
            LeEleitor(eleicao->eleitores[i]);
        }
    }
    for (int i = 0; i < eleicao->totalEleitores; i++)
    {
        if (i < MAX_ELEITORES)
        {
            for (int j = 0; j < i; j++)
            {
                if (EhMesmoEleitor(eleicao->eleitores[i], eleicao->eleitores[j]))
                {
                    printf("ELEICAO ANULADA\n");
                    exit(1);
                }
            }
        }
    }
    encontrou = 0;
    for (int i = 0; i < eleicao->totalEleitores; i++)
    {
        if (i < MAX_ELEITORES)
        {
            if (ObtemVotoPresidente(eleicao->eleitores[i]) == 0)
            {
                eleicao->votosBrancosPresidente++;
            }
            else
            {
                encontrou = 0;
                for (int j = 0; j < eleicao->totalPresidentes; j++)
                {
                    if (VerificaIdCandidato(eleicao->presidentes[j], ObtemVotoPresidente(eleicao->eleitores[i])))
                    {
                        IncrementaVotoCandidato(eleicao->presidentes[j]);
                        encontrou++;
                        break;
                    }
                }
                if (!encontrou)
                {
                    eleicao->votosNulosPresidente++;
                }
            }
            if (ObtemVotoGovernador(eleicao->eleitores[i]) == 0)
            {
                eleicao->votosBrancosGovernador++;
            }
            else
            {
                encontrou = 0;
                for (int j = 0; j < eleicao->totalGovernadores; j++)
                {

                    if (VerificaIdCandidato(eleicao->governadores[j], ObtemVotoGovernador(eleicao->eleitores[i])))
                    {
                        IncrementaVotoCandidato(eleicao->governadores[j]);
                        encontrou++;
                        break;
                    }
                }
                if (!encontrou)
                {
                    eleicao->votosNulosGovernador++;
                }
            }
        }
    }
}

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao *eleicao)
{
    int win = 0;
    int empate = 0;
    printf("- PRESIDENTE ELEITO: ");
    for (int i = 1; i < eleicao->totalPresidentes; i++)
    {
        if (ObtemVotos(eleicao->presidentes[i]) > ObtemVotos(eleicao->presidentes[win]))
        {
            win = i;
            empate = 0;
        }
        else if (ObtemVotos(eleicao->presidentes[i]) == ObtemVotos(eleicao->presidentes[win]) && !EhMesmoCandidato(eleicao->presidentes[i], eleicao->presidentes[win]))
        {
            empate++;
        }
    }
    if (empate)
    {
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    }
    else if ((eleicao->votosBrancosPresidente + eleicao->votosNulosPresidente) >= ObtemVotos(eleicao->presidentes[win]))
    {
        printf("SEM DECISAO\n");
    }
    else
    {
        ImprimeCandidato(eleicao->presidentes[win], CalculaPercentualVotos(eleicao->presidentes[win], eleicao->totalEleitores));
    }
    printf("- GOVERNADOR ELEITO: ");
    empate = 0;
    win = 0;
    for (int i = 1; i < eleicao->totalGovernadores; i++)
    {
        if (ObtemVotos(eleicao->governadores[i]) > ObtemVotos(eleicao->governadores[win]))
        {
            win = i;
            empate = 0;
        }
        else if (ObtemVotos(eleicao->governadores[i]) == ObtemVotos(eleicao->governadores[win]) && !EhMesmoCandidato(eleicao->governadores[i], eleicao->governadores[win]))
        {
            empate++;
        }
    }
    if (empate)
    {
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    }
    else if ((eleicao->votosBrancosGovernador + eleicao->votosNulosGovernador) >= ObtemVotos(eleicao->governadores[win]))
    {
        printf("SEM DECISAO\n");
    }
    else
    {
        ImprimeCandidato(eleicao->governadores[win], CalculaPercentualVotos(eleicao->governadores[win], eleicao->totalEleitores));
    }
    printf("- NULOS E BRANCOS: %d, %d", (eleicao->votosNulosGovernador + eleicao->votosNulosPresidente), (eleicao->votosBrancosGovernador + eleicao->votosBrancosPresidente));
}
