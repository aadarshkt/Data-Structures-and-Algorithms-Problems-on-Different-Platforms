#include <bits/stdc++.h>
using namespace std;

// Basically we take any starting point(s) then print all the vertices of that disconnected graph and make them visited.
// We do that for all the vertices.

//Time complexity --> O(v + e) //se the queue everyone is present in queue. v because if the vertices are completely disconnected.
//basically you will loop through every element of the adjencency list so 
//Actually time complexity is O(2 * v + 2 * e) which is equivalent to O(v + e);

void addEdge(vector<int> adj[], int u, int v)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void printBFS(vector<int> adj[], int v, int s, bool visited[])
{

    visited[s] = true;

    queue<int> q;
    q.push(s);

    while (q.empty() == false)
    {
        s = q.front();
        cout << s << " ";
        q.pop();

        for (int i = 0; i < adj[s].size(); i++)
        {
            if (visited[adj[s][i]] == false)
            {
                visited[adj[s][i]] = true;
                q.push(adj[s][i]);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v = 7;

    vector<int> adj[v];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);

    addEdge(adj, 4, 5);
    addEdge(adj, 4, 6);

    bool visited[v];

    for(int i=0; i<v; i++) visited[i] = false;

    int count = 0;

    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            count++;//count no of diconnencted graph.
            printBFS(adj, v, i, visited);
        }
    }
    cout << endl;

    cout << count << endl;

    return 0;
}