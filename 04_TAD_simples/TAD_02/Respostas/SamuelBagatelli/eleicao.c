#include "eleicao.h"
#include "candidato.h"
#include "eleitor.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATOS 6

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
        int votoG = ObtemVotoGovernador(eleitor);

        int i;
        for (i = 0; i < MAX_CANDIDATOS_POR_CARGO; i++)
        {
            if (VerificaIdCandidato(eleicao.presidentes[i], votoP))
                eleicao.presidentes[i] = IncrementaVotoCandidato(eleicao.presidentes[i]);

            if (VerificaIdCandidato(eleicao.governadores[i], votoG))
                eleicao.governadores[i] = IncrementaVotoCandidato(eleicao.governadores[i]);
        }
    }
}