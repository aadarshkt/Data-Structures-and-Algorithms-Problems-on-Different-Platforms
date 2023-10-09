#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int u, bool visited[])
{
    visited[u] = true;

    int size = adj[u].size();

    for (int i = 0; i < size; i++)
    {
        if (!visited[adj[u][i]])
            dfs(adj, adj[u][i], visited);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool visited[n + 1] = {0};

    vector<int> ans;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            ans.push_back(i);
            dfs(adj, i, visited);
        }
    }

    int size = ans.size();

    if (size >= 2)
    {
        cout << size - 1 << endl;

        for (int i = 0; i < size - 1; i++)
        {
            cout << ans[i] << " " << ans[i + 1] << endl;
        }
    }
    else
        cout << 0 << endl;

    return 0;
}