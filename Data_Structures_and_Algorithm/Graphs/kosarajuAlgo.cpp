#include <bits/stdc++.h>
using namespace std;

// It is used to find strongly connected components in a graph.

// SCC is subgraph such that every vertex is reachable by every other vertex. or for every node you can reach every other node.
// Think in terms of city. A city from which from you can reach every other city but that should be true for every vertex of that component.

// Given two distinct scc you can go to other scc but cannot comeback.
// If you can comeback they are the same scc.

// steps

// do a dfs(topological) with stack.
// Transpose.
// print it. with tranpose adjacency list and stack. formed in 1st step.

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void topologicalSort(vector<int> adj[], int s, int v, bool visited[], stack<int> &st)
{
    visited[s] = true;

    for (int i = 0; i < adj[s].size(); i++)
    {
        if (visited[adj[s][i]] == false)
        {
            visited[adj[s][i]] = true;
            topologicalSort(adj, adj[s][i], v, visited, st);
        }
    }

    st.push(s);
}

void DFSprint(vector<int> adj[], int s, bool visited[])
{
    if (visited[s] == true)
    {
        return;
    }

    visited[s] = true;
    cout << s << " ";

    for (int i = 0; i < adj[s].size(); i++)
    {
        if (visited[adj[s][i]] == false)
        {
            DFSprint(adj, adj[s][i], visited);
        }
    }
}

void transpose(vector<int> adj[], vector<int> tr[], int v)
{
    for (int i = 0; i < v; i++)
    {
        for (auto it = adj[i].begin(); it != adj[i].end(); ++it)
        {
            tr[*it].push_back(i);
        }
    }
}

void kosaraju(vector<int> adj[], int s, int v, bool visited[], stack<int> &st)
{
    // step 1
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            topologicalSort(adj, s, v, visited, st);
        }
    }

    for (int i = 0; i < v; i++)
        visited[i] = false;

    // step 2
    vector<int> tr[v];

    transpose(adj, tr, v);

    while (st.empty() == false)
    {
        int top = st.top();
        st.pop();

        if (visited[top] == false)
        {
            DFSprint(tr, top, visited);
            cout << endl;
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

    addEdge(adj, 1, 0);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 3, 4);

    bool visited[v];

    for (int i = 0; i < v; i++)
        visited[i] = false;

    stack<int> st;

    kosaraju(adj, 0, v, visited, st);

    return 0;
}