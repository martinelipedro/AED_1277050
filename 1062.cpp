/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Pedro Martineli
Linguagem   : C++
Problema    : https://judge.beecrowd.com/pt/problems/view/1062
Data        : 11/10/2026
Objetivo    : Pilha para stackar ou passar os vagões diretamente
Dificuldade : Tranquilo.
-------------------------------------------------------------------------- */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    while (cin >> n && n != 0)
    {
        while (true)
        {
            int B[1000];
            cin >> B[0];

            if (B[0] == 0)
                break;
            for (int i = 1; i < n; i++) cin >> B[i];

            stack<int> station;
            int next = 1;
            bool possible = true;

            for (int i = 0; i < n; i++)
            {
                while (next <= n && (station.empty() || station.top() != B[i]))
                {
                    station.push(next);
                    next++;
                }

                if (!station.empty() && station.top() == B[i])
                    station.pop();
                else
                    possible = false;
            }

            cout << (possible ? "Yes" : "No") << '\n';
        }

        cout << '\n';
    }

    return 0;
}