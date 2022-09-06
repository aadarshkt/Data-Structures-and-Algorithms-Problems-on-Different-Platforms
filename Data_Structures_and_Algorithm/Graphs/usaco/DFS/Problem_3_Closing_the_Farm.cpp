#include <bits/stdc++.h>
using namespace std;

// function to return number of nodes reached.
int dfs(vector<int> adj[], int u, bool visited[], vector<bool> &state)
{
    visited[u] = 1;

    int size = adj[u].size();

    int ans = 0;

    for (int i = 0; i < size; i++)
    {
        if (!visited[adj[u][i]])
        {
            ans += state[adj[u][i]] == 1 ? (1 + dfs(adj, adj[u][i], visited, state)) : 0;
        }
    }

    return ans;
}

void setIO(string name = "")
{
    cin.tie(0)->sync_with_stdio(0);
    if (name.length())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<bool> state(n + 1, 1); // state of open or close.
    bool visited[n + 1] = {0};
    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int closed[n];
    for (int i = 0; i < n; i++)
    {
        cin >> closed[i];
    }

    int lastClosed = closed[n - 1];

    int depth = dfs(adj, lastClosed, visited, state);

    depth == n - 1 ? cout << "YES" << endl : cout << "NO" << endl;

    for (int i = 0; i < n - 1; i++)
    {
        state[closed[i]] = 0;

        for(int i=1; i<=n; i++) visited[i] = 0;

        depth = dfs(adj, lastClosed, visited, state);

        depth != (n - 1 - (i + 1)) ? cout << "NO" << endl : cout << "YES" << endl;
    }

    return 0;
}