#include <stdio.h>
#include <stdlib.h>
#include "defesa.h"

struct defesa
{
    char nome[MAX_TAM];

    float x;

    float y;

    char tipo;

    float tamanho;

    float poder;

    int quantidade;
};

tDefesa LeDefesa()
{
    tDefesa d = malloc(sizeof(tDefesa));

    scanf("%s", d->nome);

    scanf("%f %f", &(d->x), &(d->y));

    scanf("%c", &(d->tipo));

    scanf("%f %d", &(d->poder), &(d->quantidade));

    return d;
}

void ImprimeDefesa(tDefesa defesa)
{
    printf("%s: %d", defesa->nome, defesa->quantidade);
}

void LiberaDefesa(tDefesa defesa)
{
    free(defesa);
}
