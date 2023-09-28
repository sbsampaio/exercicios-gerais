#include "eleicao.h"
#include "candidato.h"
#include "eleitor.h"
#include <stdio.h>
#include <stdlib.h>

tEleicao InicializaEleicao()
{
    int totalCandidatos;
    scanf("%d", &totalCandidatos);

    tEleicao eleicao;

    eleicao.totalPresidentes = 0;

    eleicao.totalGovernadores = 0;

    eleicao.votosBrancosPresidente = 0;
    eleicao.votosNulosPresidente = 0;

    eleicao.votosBrancosGovernador = 0;
    eleicao.votosNulosGovernador = 0;

    eleicao.totalEleitores = 0;

    while (totalCandidatos--)
    {
        tCandidato candidato = LeCandidato();

        char cargo = ObtemCargo(candidato);

        if (cargo == 'P')
        {
            eleicao.presidentes[eleicao.totalPresidentes] = candidato;
            eleicao.totalPresidentes++;
        }
        else if (cargo == 'G')
        {
            eleicao.governadores[eleicao.totalGovernadores] = candidato;
            eleicao.totalGovernadores++;
        }
    }
}

tEleicao RealizaEleicao(tEleicao eleicao)
{
    int totalEleitores;
    scanf("%d", &totalEleitores);

    while (totalEleitores--)
    {
        tEleitor eleitor = LeEleitor();
        eleicao.eleitores[eleicao.totalEleitores] = eleitor;
        eleicao.totalEleitores++;

        int votoP = ObtemVotoPresidente(eleitor);

        if (votoP == 0)
            eleicao.votosBrancosPresidente++;

        int votoG = ObtemVotoGovernador(eleitor);

        if (votoG == 0)
            eleicao.votosBrancosGovernador++;

        int i, contP = 0, contG = 0;
        for (i = 0; i < MAX_CANDIDATOS_POR_CARGO; i++)
        {
            if (VerificaIdCandidato(eleicao.presidentes[i], votoP))
                eleicao.presidentes[i] = IncrementaVotoCandidato(eleicao.presidentes[i]);
            else
                contP++;

            if (VerificaIdCandidato(eleicao.governadores[i], votoG))
                eleicao.governadores[i] = IncrementaVotoCandidato(eleicao.governadores[i]);
            else
                contG++;
        }

        if (contP >= 3)
            eleicao.votosNulosPresidente++;

        if (contG >= 3)
            eleicao.votosNulosGovernador++;
    }

    return eleicao;
}

void TrocaPosicao(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void ImprimeResultadoEleicao(tEleicao eleicao)
{
    if (eleicao.totalEleitores > MAX_ELEITORES)
    {
        printf("ELEICAO ANULADA");
        return;
    }

    if (eleicao.totalGovernadores > MAX_CANDIDATOS_POR_CARGO || eleicao.totalPresidentes > MAX_CANDIDATOS_POR_CARGO)
    {
        printf("ELEICAO ANULADA");
        return;
    }

    int i, j;

    for (i = 0; i < eleicao.totalEleitores - 1; i++)
    {
        for (j = 0; j < eleicao.totalEleitores - i - 1; j++)
        {
            if (EhMesmoEleitor(eleicao.eleitores[j], eleicao.eleitores[j + 1]))
            {
                printf("ELEICAO ANULADA");
                return;
            }
        }
    }
}