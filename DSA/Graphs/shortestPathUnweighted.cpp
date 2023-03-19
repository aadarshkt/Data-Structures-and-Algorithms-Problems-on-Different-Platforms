#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

//Time complexity -> O(v + e)

//Program to find shortest of any vertext from source vertex.

//BFS implentation.

void shortestPath(vector<int> adj[], int s, bool visited[], int dist[])
{
    visited[s] = true;

    queue<int> q;
    q.push(s);

    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();

        for (int i = 0; i < adj[u].size(); i++)
        {
            if (visited[adj[u][i]] == false)
            {
                dist[adj[u][i]] = dist[u] + 1; //Most important to understand.//Take exmaple. all adjacent will have distance one from source vertex. Then 2 then 3
                q.push(adj[u][i]);
                visited[adj[u][i]] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v = 4;

    vector<int> adj[v];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);

    bool visited[v];
    int dist[v] = {0};

    shortestPath(adj, 0, visited, dist);

    for (int i = 0; i < v; i++)
        cout << dist[i] << " ";

    return 0;
}