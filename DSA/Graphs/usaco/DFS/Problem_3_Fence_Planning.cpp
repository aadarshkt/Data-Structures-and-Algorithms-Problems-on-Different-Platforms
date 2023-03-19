#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int u, vector<bool> &visited,
 pair<int, int> &maxPair, pair<int, int> &minPair, int x[], int y[])
{
    visited[u] = 1;

    maxPair.first = max(maxPair.first, x[u]);
    maxPair.second = max(maxPair.second, y[u]);

    minPair.first = min(minPair.first, x[u]);
    minPair.second = min(minPair.second, y[u]);

    int n = adj[u].size();

    for(int i=0; i<n; i++)
    {
        if(!visited[adj[u][i]]) dfs(adj, adj[u][i], visited, maxPair, minPair, x, y);
    }
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

    int x[n + 1], y[n + 1];

    for(int i=1; i<=n; i++)
    {
        cin >> x[i] >> y[i];
    }

    vector<int> adj[n + 1];

    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(n + 1, 0);

    int peri = INT_MAX;

    for(int i=1; i<=n; i++)
    {
        pair<int, int> maxPair(make_pair(INT_MIN, INT_MIN));
        pair<int, int> minPair(make_pair(INT_MAX, INT_MAX));

        if(!visited[i]) dfs(adj, i, visited, maxPair, minPair, x, y);
        else continue;

        int diffX = abs(maxPair.first - minPair.first);
        int diffY = abs(maxPair.second - minPair.second);

        int tempPeri = 2 * diffX + 2 * diffY;

        peri = min(peri, tempPeri);
    }

    cout << peri << endl;

    return 0;
}