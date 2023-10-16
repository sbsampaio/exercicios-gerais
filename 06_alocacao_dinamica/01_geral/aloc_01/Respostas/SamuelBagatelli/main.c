#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main(int argc, char *argv[])
{
    int tamanho;

    scanf("%d", &tamanho);

    int *vet = CriaVetor(tamanho);

    LeVetor(vet, tamanho);

    float media = CalculaMedia(vet, tamanho);

    LiberaVetor(vet);

    printf("%.2f\n", media);

    return 0;
}
