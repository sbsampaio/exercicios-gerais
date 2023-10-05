#include <stdio.h>
#include <string.h>
#include "aluno.h"

tAluno CriaAluno(char *nome, int matricula, int n1, int n2, int n3)
{
    tAluno aluno;

    strcpy(aluno.nome, nome);

    aluno.matricula = matricula;

    aluno.n1 = n1;
    aluno.n2 = n2;
    aluno.n3 = n3;

    return aluno;
}

tAluno LeAluno()
{
    char nome[50];

    scanf("%s", nome);

    int matricula;

    scanf("%d", &matricula);

    int n1, n2, n3;

    scanf("%d%d%d", &n1, &n2, &n3);

    return CriaAluno(nome, matricula, n1, n2, n3);
}

int ComparaMatricula(tAluno aluno1, tAluno aluno2)
{
    if (aluno1.matricula > aluno2.matricula)
        return 1;
    if (aluno2.matricula > aluno1.matricula)
        return -1;

    return 0;
}

int CalculaMediaAluno(tAluno aluno)
{
    int media;

    media = (aluno.n1 + aluno.n2 + aluno.n3) / 3;

    return media;
}

int VerificaAprovacao(tAluno aluno)
{
    int media = CalculaMediaAluno(aluno);

    if (media >= 7)
        return 1;

    return 0;
}

void ImprimeAluno(tAluno aluno)
{
    printf("%s\n", aluno.nome);
}