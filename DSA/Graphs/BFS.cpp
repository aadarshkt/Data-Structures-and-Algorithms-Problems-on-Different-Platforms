#include <bits/stdc++.h>
using namespace std;

// list is like double linked list. Non contigous memeory locations are used.

// queue stl --> pushes from back deletes from front.
// 1) q.front() prints first element of the queue.
// 2) q.pop() delete last element.

//You can imagine BFS with friends network. U print first your friends then theirs friends.

void addEdge(vector<int> adj[], int u, int v)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void BFS(vector<int> adj[], int s, int v)
{

    vector<bool> visited;
    visited.resize(v, false);

    queue<int> q;

    visited[s] = true;
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

    int v = 6;

    vector<int> adj[v];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 5);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 5);

    BFS(adj, 0, 6);

    return 0;
}