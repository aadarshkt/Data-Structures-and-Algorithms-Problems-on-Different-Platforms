#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}


//Time complexity --> O(V + E)

void DFS(vector<int> adj[], int s, bool visited[])
{

    if(visited[s] == true) return;

    visited[s] = true;

    cout << s << " ";

    for (int i = 0; i < adj[s].size(); i++)
    {
        if (visited[adj[s][i]] == false)
            DFS(adj, adj[s][i], visited);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v = 6;

    vector<int> adj[v];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 5);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 5);

    bool visited[v];

    for(int i=0; i<v; i++) visited[i] = false;

    DFS(adj, 0, visited);

    return 0;
}