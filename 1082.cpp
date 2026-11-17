#include <bits/stdc++.h>

using namespace std;
string dfs(vector<int> &visited, vector<vector<int>> &adj, int vt)
{
    stack<int> st;
    st.push(vt);
    visited[vt] = 1;
    string str;

    while (!st.empty())
    {
        int v = st.top();
        st.pop();

        str += (char)('a' + v - 1);
        for (int u : adj[v])
        {
            if (!visited[u])
            {
                visited[u] = 1;
                st.push(u);
            }
        }
    }

    sort(str.begin(), str.end());
    return str;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int c = 1; c <= n; ++c)
    {
        cout << "Case #" << c << ":\n";
        int v, e;
        cin >> v >> e;
        vector<vector<int>> adj(v + 1);
        while (e--)
        {
            char ac, bc;
            cin >> ac >> bc;
            int a = ac - 'a' + 1;
            int b = bc - 'a' + 1;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> visited(v + 1, 0);
        int total = 0;
        for (int i = 1; i <= v; ++i)
        {
            if (!visited[i])
            {
                for (char vertex : dfs(visited, adj, i)) cout << vertex << ',';
                cout << '\n';
                total++;
            }
        }

        cout << total << " connected components\n\n";
    }
}
asd