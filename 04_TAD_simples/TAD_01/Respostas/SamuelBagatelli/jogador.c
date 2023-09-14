#include <stdio.h>
#include "jogador.h"
#include "jogada.h"

tJogador CriaJogador(int idJogador)
{
    tJogador jogador;

    jogador.id = idJogador;

    return jogador;
}

tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    tJogada jogada = LeJogada();

    int x = ObtemJogadaX(jogada);
    int y = ObtemJogadaY(jogada);

    tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, x, y);
}