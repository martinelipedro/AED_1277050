/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Pedro Martineli
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 11/10/2026
Objetivo    : Encontrar o maior valor e sua posicao
Dificuldade : -
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *values = (int *)malloc(100 * sizeof(int));
    int pos = 0;

    for (int i = 0; i < 100; ++i) scanf("%d", &values[i]);

    for (int i = 1; i < 100; ++i)
    {
        if (values[i] > values[pos])
            pos = i;
    }

    printf("%d\n%d\n", values[pos], pos + 1);
    free(values);
}
