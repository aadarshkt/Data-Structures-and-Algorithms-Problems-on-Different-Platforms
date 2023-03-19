#include <bits/stdc++.h>
using namespace std;

void solve(int indegree[], vector<int> adj[], int u)
{
    int size = adj[u].size();
    for (int i = 0; i < size; i++)
    {
        indegree[adj[u][i]]++;
        solve(indegree, adj, adj[u][i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> adj[n + 1];

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
    }

    int indegree[n + 1] = {0};

    for (int i = 1; i <= n; i++)
    {
        solve(indegree, adj, i);
    }

    int ans = -1;

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == n - 1)
        {
            ans = i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}