#include <bits/stdc++.h>
using namespace std;

void BFS(vector<int> adj[], int u, vector<bool> &vis, int &maxi, int &sum, int cost[])
{
    vis[u] = 1;
    sum += cost[u];
    maxi = max(maxi, cost[u]);

    queue<int> q;
    q.push(u);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        int n = adj[curr].size();

        for (int i = 0; i < n; i++)
        {
            int next = adj[curr][i];
            if (!vis[next])
            {
                q.push(next);
                maxi = max(maxi, cost[next]);
                sum += cost[next];
                vis[next] = 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int cost[n];
    vector<bool> vis(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
    }

    vector<int> adj[n + 1];

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int maxi = -1, sum = -1, minimumCost = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            BFS(adj, i, vis, maxi, sum, cost);
            if (sum != -1 && maxi != -1)
                minimumCost += (sum - maxi);
            
            sum = -1, maxi = -1;
        }
    }

    cout << minimumCost << endl;

    return 0;
}