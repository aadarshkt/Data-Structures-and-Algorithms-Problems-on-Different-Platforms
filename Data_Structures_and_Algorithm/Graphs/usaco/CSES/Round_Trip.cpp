#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

bool isFound = false;
void BFS(vector<int> adj[], vector<int> &vis, int u, vector<int> &parent)
{
    vis[u] = 1;

    queue<int> q;
    q.push(u);
    q.push(-1);

    int level = 0;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        if (curr == -1)
        {
            level++;
            curr = q.front();
        }

        bool isPushed = false;
        int n = adj[curr].size();

        for (int i = 0; i < n; i++)
        {
            int next = adj[curr][i];
            if (!vis[next])
            {
                q.push(next);
                vis[next] = 1;
                parent[next] = curr;
                isPushed = true;
            }

            if (next == u && level >= 2)
            {
                parent[u] = curr;
                isFound = true;
                break;
            }
        }

        if (isFound)
            break;
        
        if(isPushed) q.push(-1);
    }
}

void DFS(vector<int> adj[], vector<int> &vis, int u, vector<int> &parent, int level, int start)
{
    vis[u] = 1;

    int n = adj[u].size();

    for(int i=0; i<n; i++)
    {
        int next = adj[u][i];
        if(next == start && level >= 2)
        {
            parent[start] = next;
            retu
        if(!vis[next])
        {
            parent[next] = u;
            DFS(adj, vis, next, parent, level + 1, start);
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> vis(n + 1, 0), parent(n + 1, -1);

    for (int i = 1; i <= n; i++)
    {
        DFS(adj, vis, i, parent, 0, i);

        if(parent[i] != -1)
        {
            int it = i;

            while(parent[it] !)
        }   
        else
        {
            vis.assign(n + 1, 0);
            parent.assign(n + 1, -1);
        }     
    }

    return 0;
}