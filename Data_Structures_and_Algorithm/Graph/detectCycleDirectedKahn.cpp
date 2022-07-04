#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void topologicalSort(vector<int> adj[], int indegree[], int v, int &count)
{

    queue<int> q;

    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            count++;
        }
    }

    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();

        for (int i = 0; i < adj[u].size(); i++)
        {
            indegree[adj[u][i]]--;
            if (indegree[adj[u][i]] == 0)
            {
                q.push(adj[u][i]);
                count++;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v = 5;

    vector<int> adj[v];

    int indegree[v];

    for (int i = 0; i < v; i++)
    {
        indegree[i] = 0;
    }

    int count = 0;

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 4, 1);

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            indegree[adj[i][j]]++;
        }
    }

    topologicalSort(adj, indegree, v, count);

    if (count != v)
        cout << "CYCLE";
    else
        cout << "No cycle";

    return 0;
}