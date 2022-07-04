#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

//basically if a node goes to node which is visited as well as recursion stack is true
//then a directed cycle is present.

//Draw the graph of the below example. for 1 and 5 if they would be connected then also our solution would work
//Because recSt would false for one.

//For imaginaton. If our path recusion reaches to current recursion stack (called back edge) we would have a cycle.
//If 4 and 5 are connected bidirectionally then also we would detect a cycle. --> A flaw.

//Time complexity --> O(v + e)

void detectCycle(vector<int> adj[], int s, bool visited[], bool rectSt[], bool &ans)
{
    visited[s] = true;
    rectSt[s] = true;

    for (int i = 0; i < adj[s].size(); i++)
    {
        if (visited[adj[s][i]] == false)
        {
            visited[adj[s][i]] = true;
            detectCycle(adj, adj[s][i], visited, rectSt, ans);
        }

        if (visited[adj[s][i]] == true && rectSt[adj[s][i]] == true)
            ans = true;
    }

    rectSt[s] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v = 6;

    vector<int> adj[v];

    bool visited[v], recSt[v];

    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        recSt[i] = false;
    }

    addEdge(adj, 0, 1);
    addEdge(adj, 2, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 3);

    bool ans = false;

    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            detectCycle(adj, i, visited, recSt, ans);
        }
    }

    if (ans)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}