#include <bits/stdc++.h>
using namespace std;

void addEdges(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void longestPath(vector<int> adj[], int s, int dist[], int parent[])
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
            {
                dist[adj[u][i]] = dist[u] + 1;
                parent[adj[u][i]] = u;
            }

            // since it is directed we don't have to think of the visited part.
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

    int dist[n + 1], parent[n + 1];

    vector<int> trace;

    for (int i = 1; i < n + 1; i++)
    {
        dist[i] = INT_MIN;
        parent[i] = -1;
    }

    dist[1] = 0;

    longestPath(adj, 1, dist, parent);

    int index = n;

    while (index != -1)
    {
        trace.push_back(index);
        index = parent[index];
    }

    reverse(trace.begin(), trace.end());

    if (trace[0] != 1)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    int size = trace.size();

    cout << size << endl;

    for (int i = 0; i < size; i++)
    {
        cout << trace[i] << " ";
    }

    cout << endl;

    return 0;
}