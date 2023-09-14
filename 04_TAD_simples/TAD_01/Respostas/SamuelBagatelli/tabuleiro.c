#include <stdio.h>
#include "tabuleiro.h"

tTabuleiro CriaTabuleiro()
{
    tTabuleiro tabuleiro;

    tabuleiro.peca1 = 'X';
    tabuleiro.peca2 = '0';

    tabuleiro.pecaVazio = '-';

    int i, j;

    for (i = 0; i < TAM_TABULEIRO; i++)
    {
        for (j = 0; j < TAM_TABULEIRO; j++)
        {
            tabuleiro.posicoes[i][j] = tabuleiro.pecaVazio;
        }
    }

    return tabuleiro;
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y)
{
    char simbolo;

    if (peca == 1)
        simbolo = 'X';

    if (peca == 2)
        simbolo = '0';

    if (EstaLivrePosicaoTabuleiro(tabuleiro, x, y))
    {
        tabuleiro.posicoes[x][y] = simbolo;
    }

    return tabuleiro;
}

int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro)
{
    int i, j;

    for (i = 0; i < TAM_TABULEIRO; i++)
    {
        for (j = 0; j < TAM_TABULEIRO; j++)
        {
            char posicao = tabuleiro.posicoes[i][j];

            if (!EstaLivrePosicaoTabuleiro(tabuleiro, i, j))
                return 0;
        }
    }

    return 1;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca)
{
    char poiscao = tabuleiro.posicoes[x][y];

    char simbolo;

    if (peca == 1)
        simbolo = 'X';

    if (peca == 2)
        simbolo = '0';

    if (poiscao == simbolo)
        return 1;

    return 0;
}

int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y)
{
    return (tabuleiro.posicoes[x][y] == '-');
}

int EhPosicaoValidaTabuleiro(int x, int y)
{
    if (x > 2 || x < 0)
        return 0;

    if (y > 2 || x < 0)
        return 0;

    return 1;
}

void ImprimeTabuleiro(tTabuleiro tabuleiro)
{
    int i, j;

    for (i = 0; i < TAM_TABULEIRO; i++)
    {
        for (j = 0; j < TAM_TABULEIRO; j++)
            printf("%c", tabuleiro.posicoes[i][j]);

        printf("\n");
    }
}