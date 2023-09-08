#include <stdio.h>
#include "data.h"

int verificaDataValida(int dia, int mes, int ano)
{
    if (dia > 31 || dia < 1)
        return 0;

    if (verificaBissexto(ano))
    {
        if (dia > 29 && mes == 2)
            return 0;
    }
    else
    {
        if (dia > 28 && mes == 2)
            return 0;
    }

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        if (dia > 30)
            return 0;
    }

    return 1;
}

void imprimeMesExtenso(int mes)
{
    switch (mes)
    {
    case 1:
        printf("Janeiro ");
        break;

    case 2:
        printf("Fevereiro ");
        break;

    case 3:
        printf("Marco ");
        break;

    case 4:
        printf("Abril ");
        break;

    case 5:
        printf("Maio ");
        break;

    case 6:
        printf("Junho ");
        break;

    case 7:
        printf("Julho ");
        break;

    case 8:
        printf("Agosto ");
        break;

    case 9:
        printf("Setembro ");
        break;

    case 10:
        printf("Outubro ");
        break;

    case 11:
        printf("Novembro ");
        break;

    case 12:
        printf("Dezembro ");
        break;
    }
}

void imprimeDataExtenso(int dia, int mes, int ano)
{
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf("de %04d\n", ano);
}

int verificaBissexto(int ano)
{
    if (!(ano % 100))
    {
        return !(ano % 400);
    }

    return !(ano % 4);
}

int numeroDiasMes(int mes, int ano)
{
    if (verificaBissexto(ano) && mes == 2)
        return 29;

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
        return 30;

    return 31;
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    if (ano1 < ano2)
        return 1;
    else if (ano1 == ano2)
    {
        if (mes1 < mes2)
            return 1;
        else if (mes1 == mes2)
        {
            if (dia1 < dia2)
                return 1;
            else if (dia1 == dia2)
                return 0;
            else
                return -1;
        }
        else
            return -1;
    }
    else
        return -1;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    int difAno = ano1 - ano2;
    int difMes = mes1 - mes2;
    int difDia = dia1 - dia2;
}