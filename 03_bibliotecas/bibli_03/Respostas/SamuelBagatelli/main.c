#include <stdio.h>
#include "data.h"

int main()
{
    int dia1, mes1, ano1;
    int dia2, mes2, ano2;

    scanf("%d/%d/%d", &dia1, &mes1, &ano1);
    scanf("%d/%d/%d", &dia2, &mes2, &ano2);

    if (!verificaDataValida(dia1, mes1, ano1) || !verificaDataValida(dia2, mes2, ano2))
    {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        return 1;
    }

    printf("Primeia data: ");
    imprimeDataExtenso(dia1, mes1, ano1);

    printf("Segunda data: ");
    imprimeDataExtenso(dia2, mes2, ano2);

    switch (comparaData(dia1, mes1, ano1, dia2, mes2, ano2))
    {
    case -1:
        printf("A primeira data eh mais antiga\n");
        break;

    case 1:
        printf("A segunda data eh mais antiga\n");
        break;

    case 0:
        printf("As datas sao iguais\n");
        break;
    }

    printf("A diferenca em dias entre as datas eh: %d dias\n", calculaDiferencaDias(dia1, mes1, ano1, dia2, mes2, ano2));

    return 0;
}