#include <stdio.h>
#include <stdlib.h>
#include "missil.h"

struct missil
{
    char nome[MAX_TAM];

    float x;

    float y;

    float poder;
};

tMissil LeMissil()
{
    tMissil m = malloc(sizeof(tMissil));

    scanf("%s", m->nome);

    scanf("%f %f", &(m->x), &(m->y));

    scanf("%f", &(m->poder));

    return m;
}

void ImprimeMissil(tMissil missil)
{
    printf("%s: %f", missil->nome, missil->poder);
}

void LiberaMissil(tMissil missil)
{
    free(missil);
}

float GetMissilY(tMissil missil)
{
    return missil->y;
}

float GetMissilX(tMissil missil)
{
    return missil->x;
}

float GetMissilPoder(tMissil missil)
{
    return missil->poder;
}

void ReduzPoder(tMissil missil, float valor)
{
    missil->poder -= valor;
}
