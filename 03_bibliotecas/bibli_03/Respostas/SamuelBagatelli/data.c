#include <stdio.h>
#include "data.h"

int verificaDataValida(int dia, int mes, int ano)
{
}

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

void imprimeDataExtenso(int dia, int mes, int ano)
{
    printf("%2d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %4d", ano);
}