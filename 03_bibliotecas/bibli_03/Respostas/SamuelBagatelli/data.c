#include <stdio.h>
#include "data.h"

#define DIAS_ANO 365

int verificaDataValida(int dia, int mes, int ano)
{
    if (mes == 2)
    {
        if (verificaBissexto(ano))
        {
            if (dia > 29)
                return 0;
        }
        else if (dia > 28)
            return 0;
    }

    if (dia < 1 || dia > 31)
        return 0;

    if (mes < 1 || mes > 12)
        return 0;

    if (ano < 1)
        return 0;

    return 1;
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
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %04d\n", ano);
}

int verificaBissexto(int ano)
{
    if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
        return 1;

    return 0;
}

int numeroDiasMes(int mes, int ano)
{
    if (mes == 2)
    {
        if (verificaBissexto(ano))
            return 29;

        return 28;
    }

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
        return 30;

    return 31;
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    if (ano1 > ano2)
        return 1;
    if (ano1 < ano2)
        return -1;

    if (mes1 > mes2)
        return 1;
    if (mes1 < mes2)
        return -1;

    if (dia1 > dia2)
        return 1;
    if (dia1 < dia2)
        return -1;

    return 0;
}

int calculaDiasAteMes(int mes, int ano)
{
    int dias = 0;

    for (int i = 1; i <= mes; i++)
    {
        dias += numeroDiasMes(i, ano);
    }

    return dias - 1;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    int resultado = 0;

    int comparacao = comparaData(dia1, mes1, ano1, dia2, mes2, ano2);

    if (comparacao == 0)
        return 0;

    int diaInicial, mesInicial, anoInicial;
    int diaFinal, mesFinal, anoFinal;

    if (comparacao < 0)
    {
        diaInicial = dia1;
        mesInicial = mes1;
        anoInicial = ano1;
        diaFinal = dia2;
        mesFinal = mes2;
        anoFinal = ano2;
    }
    else
    {
        diaInicial = dia2;
        mesInicial = mes2;
        anoInicial = ano2;
        diaFinal = dia1;
        mesFinal = mes1;
        anoFinal = ano1;
    }

    while (anoInicial < anoFinal)
    {
        resultado += verificaBissexto(anoInicial) ? DIAS_ANO + 1 : DIAS_ANO;
        anoInicial++;
    }

    int partida = calculaDiasAteMes(mesInicial - 1, anoInicial) + diaInicial;

    int sobra = calculaDiasAteMes(mesFinal - 1, anoFinal) + diaFinal;

    resultado += sobra - partida;

    return resultado;
}