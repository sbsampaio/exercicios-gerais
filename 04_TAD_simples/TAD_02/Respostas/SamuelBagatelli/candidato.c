#include "candidato.h"
#include <stdio.h>
#include <string.h>

tCandidato CriaCandidato(char *nome, char *partido, char cargo, int id)
{
    tCandidato candidato;

    strcpy(candidato.nome, nome);
    strcpy(candidato.partido, partido);
    candidato.cargo = cargo;
    candidato.id = id;
}

tCandidato LeCandidato()
{
    char nome[50];
    scanf("%[^,],", nome);
    
    char partido[50];
    scanf("%[^,],", partido);

    char cargo;
    scanf("%c,", &cargo);

    int id;
    scanf("%d", &id);

    return CriaCandidato(nome, partido, cargo, id);
}

int VerificaIdCandidato(tCandidato candidato, int id)
{
    return candidato.id == id ? 1 : 0;
}

int EhMesmoCandidato(tCandidato candidato1, tCandidato candidato2)
{
    int id = candidato2.id;

    return VerificaIdCandidato(candidato1, id);
}

char ObtemCargo(tCandidato candidato)
{
    return candidato.cargo;
}

tCandidato IncrementaVotoCandidato(tCandidato candidato)
{
    candidato.votos++;

    return candidato;
}

int ObtemVotos(tCandidato candidato)
{
    return candidato.votos;
}

float CalculaPercentualVotos(tCandidato candidato, int totalVotos)
{
    float percentual = (ObtemVotos(candidato) / (float)totalVotos) * 100;

    return percentual;
}

void ImprimeCandidato(tCandidato candidato, float percentualVotos)
{
    // Imprime Nome
    printf("%s ", candidato.nome);

    // Imprime Partido
    printf("(%s), ", candidato.partido);

    // Imprime Votos
    printf("%d voto(s), ", candidato.votos);

    // Imprime Percentual de Votos
    printf("%.2f%", percentualVotos);
}