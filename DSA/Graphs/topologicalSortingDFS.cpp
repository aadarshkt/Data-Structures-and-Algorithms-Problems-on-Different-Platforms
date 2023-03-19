#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

// use stack.

//Time complexity --> O(v + e)

void topologicalSorting(vector<int> adj[], bool visited[], int s, stack<int> &st)
{
    visited[s] = true;

    for(int i=0; i<adj[s].size(); i++)
    {
        //doing for every adjacent for starting vertex.
        if(visited[adj[s][i]] == false)
            topologicalSorting(adj, visited, adj[s][i], st);
    }

    st.push(s);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v = 6;

    vector<int> adj[v];

    bool visited[v];

    for(int i=0; i<v; i++) visited[i] = false;

    stack<int> st;

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 5);

    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            topologicalSorting(adj, visited, i, st);
        }
    }

    while(st.empty() == false)
    {
        int a = st.top();
        cout << a << " ";
        st.pop();
    }

    return 0;
}