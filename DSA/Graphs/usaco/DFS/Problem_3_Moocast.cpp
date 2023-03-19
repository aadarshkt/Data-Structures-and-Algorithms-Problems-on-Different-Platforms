#include <bits/stdc++.h>
using namespace std;

int dfs(vector<int> adj[], int u, vector<bool> &visited)
{
    visited[u] = 1;

    int size = adj[u].size();

    int ans = 0;

    for(int i=0; i<size; i++)
    {
        if(!visited[adj[u][i]]) ans += 1 + dfs(adj, adj[u][i], visited);
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

    int n;
    cin >> n;

    int x[n], y[n], p[n];

    for(int i=0; i<n; i++)
    {
        cin >> x[i] >> y[i] >> p[i];
    }

    vector<int> adj[n];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i != j)
            {
                int diff1 = x[i] - x[j];
                int diff2 = y[i] - y[j];

                diff1 *= diff1;
                diff2 *= diff2;

                int rad2 = p[i] * p[i];

                if(diff1 + diff2 <= rad2) adj[i].push_back(j);
            }
        }
    }

    vector<bool> visited(n, 0);

    int ans = -1;

    for(int i=0; i<n; i++)
    {
        visited.assign(n, 0);
        int depth = dfs(adj, i, visited) + 1;
        ans = max(ans, depth);
    }

    cout << ans << endl;

    return 0;
}