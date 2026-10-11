/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Pedro Martineli
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 11/10/2026
Objetivo    : Verificar um resultado de sudoku
Dificuldade : -
-------------------------------------------------------------------------- */

#include <stdio.h>

int main()
{
    int n, x;
    scanf("%d", &n);

    for (int s = 1; s <= n; ++s)
    {
        int valid = 1;
        int rows[9] = {0};
        int cols[9] = {0};
        int blocks[9] = {0};

        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                scanf("%d", &x);

                if (x < 1 || x > 9)
                {
                    valid = 0;
                    continue;
                }

                int bit = 1 << x;
                int block = (i / 3) * 3 + (j / 3);

                if (rows[i] & bit)
                    valid = 0;

                if (cols[j] & bit)
                    valid = 0;

                if (blocks[block] & bit)
                    valid = 0;

                rows[i] |= bit;
                cols[j] |= bit;
                blocks[block] |= bit;
            }
        }

        printf("Instancia %d\n", s);
        printf("%s\n\n", valid ? "SIM" : "NAO");
    }
}
