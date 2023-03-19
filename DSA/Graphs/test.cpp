#include <bits/stdc++.h>
using namespace std;

void addEdges(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void longestPath(vector<int> adj[], int s, int dist[])
{
    queue<int> q;

    q.push(s);

    int u;

    while (q.empty() == false)
    {
        u = q.front();
        q.pop();

        for (int i = 0; i < adj[u].size(); i++)
        {
            if (dist[adj[u][i]] < dist[u] + 1)
                dist[adj[u][i]] = dist[u] + 1;

            //since it is directed we don't have to think of the visited part.
            q.push(adj[u][i]);
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

    vector<int> adj[n + 1];

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        addEdges(adj, a, b);
    }

    int dist[n + 1];

    for(int i=1; i<n + 1; i++)
    {
        dist[i] = INT_MIN;
    }

    dist[1] = 0;

    longestPath(adj, 1, dist);

    for(int i=1; i<n+1; i++) cout << dist[i] << " ";

    return 0;
}