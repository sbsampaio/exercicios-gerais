#include <stdio.h>
#include "aluno.h"

void OrganizaPorMatricula(int tam, tAluno vetor[tam]);

int main(int argc, char const *argv[])
{
    int i;
    int numAlunos;

    scanf("%d", &numAlunos);

    tAluno vetAlunos[numAlunos];

    for (i = 0; i < numAlunos; i++)
    {
        vetAlunos[i] = LeAluno();
    }

    OrganizaPorMatricula(numAlunos, vetAlunos);

    for (i = 0; i < numAlunos; i++)
    {
        if (VerificaAprovacao(vetAlunos[i]))
            ImprimeAluno(vetAlunos[i]);
    }

    return 0;
}

void OrganizaPorMatricula(int tam, tAluno vetor[tam])
{
    int k, j;
    tAluno aux;

    for (k = tam - 1; k > 0; k--)
    {
        for (j = 0; j < k; j++)
        {
            if (ComparaMatricula(vetor[j], vetor[j + 1]) == 1)
            {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}