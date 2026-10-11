/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Pedro Martineli
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2448
Data        : 11/10/2026
Objetivo    : Busca binária para encontrar distâncias
Dificuldade : Tranquilo.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int getpos(int n, int *houses, int x)
{
    int l = 0, r = n - 1;
    while (l < r)
    {
        int m = (l + r) / 2;
        if (x <= houses[m])
            r = m;
        if (x > houses[m])
            l = m + 1;
    }

    return l;
}

int main()
{
    int n, m, current = 0, sum = 0;
    scanf("%d %d", &n, &m);
    int *houses = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) scanf("%d", &houses[i]);
    current = 0;
    for (int i = 0; i < m; ++i)
    {
        int el;
        scanf("%d", &el);
        int x = getpos(n, houses, el);
        sum += abs(x - current);
        current = x;
    }

    printf("%d\n", sum);
}