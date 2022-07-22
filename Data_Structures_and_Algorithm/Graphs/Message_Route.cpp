#include <bits/stdc++.h>
using namespace std;

void addEdges(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void shortestPath(vector<int> adj[], int s, bool visited[], int dist[], int parent[])
{
    visited[s] = true;

    queue<int> q;
    q.push(s);

    int u;

    while (q.empty() == false)
    {
        u = q.front();
        q.pop();

        for (int i = 0; i < adj[u].size(); i++)
        {
            if (visited[adj[u][i]] == false)
            {
                q.push(adj[u][i]);
                visited[adj[u][i]] = true;

                dist[adj[u][i]] = dist[u] + 1;
                parent[adj[u][i]] = u;
            }
        }
    }
}

void trace(int parent[], int n)
{
    vector<int> ans;

    ans.push_back(n);

    int index = n, count = 0;

    while (index != 1 && count < n + 1)
    {
        index = parent[index];
        ans.push_back(index);
        count++;
    }

    reverse(ans.begin(), ans.end());

    for(int i=0; i<ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    //1 based indexing.
    vector<int> adj[n + 1];

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        addEdges(adj, a, b);
    }

    bool visited[n + 1];
    int dist[n + 1];
    int parent[n + 1];

    for(int i=0; i<n+1; i++)
    {
        visited[i] = false;
        dist[i] = INT_MAX;
        parent[i] = -1;
    }

    dist[1] = 0;

    shortestPath(adj, 1, visited, dist, parent);


    if(dist[n] == INT_MAX) cout << "IMPOSSIBLE" << endl;
    else 
    {
        cout << dist[n] + 1 << endl;
        trace(parent, n);
    }


    return 0;
}