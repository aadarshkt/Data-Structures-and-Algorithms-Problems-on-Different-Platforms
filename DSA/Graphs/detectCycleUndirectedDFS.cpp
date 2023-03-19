#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

//Basic thing to understand is that if you reach a node such it's two adjacent node is already visited.
//Then a cycle must be present.

//Time complexity --> O(v + e)

void detectCycle(vector<int> adj[], int s, bool visited[], bool &ans)
{
    visited[s] = true;

    int count = 0;

    for (int i = 0; i < adj[s].size(); i++)
    {
        if (visited[adj[s][i]] == false)
        {
            visited[adj[s][i]] = true;
            detectCycle(adj, adj[s][i], visited, ans);
        }
        else
        {
            count++;
        }

        if (count >= 2)
        {
            ans = true;
            return;
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

    bool visited[v];

    //in c++ you need to run a loop.

    for (int i = 0; i < v; i++)
        visited[i] = false;

    bool ans = false;

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);

    detectCycle(adj, 0, visited, ans);

    if(ans)
        cout << "Yes";
    else 
        cout << "No";

    return 0;
}