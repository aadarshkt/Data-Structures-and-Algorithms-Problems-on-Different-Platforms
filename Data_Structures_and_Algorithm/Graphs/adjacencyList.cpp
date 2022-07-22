#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

//Time complexity --> (theta(sum of all degrees of vertices))

void printGraph(vector<int> adj[], int v)
{
    for(int i=0; i<v; i++)
    {
        for(int x : adj[i])
            cout << x << " ";
        
        cout << endl;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v = 4;

    vector<int> adj[v];

    addEdge(adj, 0, 2);
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);

    for(int i=0; i<adj[0].size(); i++)
    {
        cout << adj[0][i] << " ";
    }

    cout << endl;

    for(int i=0; i<adj[1].size(); i++)
    {
        cout << adj[1][i] << " ";
    }

    cout << endl;
    cout << endl;

    printGraph(adj, v);

    return 0;
}