#include <stdio.h>
#include <stdlib.h>

#define MAXN 10001

unsigned char **matrix;
int state[MAXN];
int n;

int cycle(int current)
{
    state[current] = 1;

    for (int i = 1; i <= n; i++)
    {
        if (matrix[current][i])
        {
            if (state[i] == 1)
                return 1;

            if (state[i] == 0 && cycle(i))
                return 1;
        }
    }

    state[current] = 2;
    return 0;
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int m, a, b;
        int hasCycle = 0;
        scanf("%d %d", &n, &m);

        matrix = malloc((n + 1) * sizeof(unsigned char *));
        for (int i = 1; i <= n; i++)
        {
            matrix[i] = calloc(n + 1, sizeof(unsigned char));
            state[i] = 0;
        }

        for (int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            matrix[a][b] = 1;
        }

        for (int i = 1; i <= n && !hasCycle; i++)
        {
            if (state[i] == 0)
                hasCycle = cycle(i);
        }

        printf("%s\n", hasCycle ? "SIM" : "NAO");

        for (int i = 1; i <= n; i++) free(matrix[i]);
        free(matrix);
    }

    return 0;
}
