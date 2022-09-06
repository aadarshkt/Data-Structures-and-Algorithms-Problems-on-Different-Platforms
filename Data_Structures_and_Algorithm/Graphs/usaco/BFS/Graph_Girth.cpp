#include <bits/stdc++.h>
using namespace std;

int BFS(vector<int> adj[], int u, vector<bool> &vis)
{
    vis[u] = 1;

    queue<int> q;
    q.push(u);
    q.push(-1);

    int level = 0;

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        if(curr == -1)
        {
            curr = q.front();
            level++;
        }

        if(curr == u) return level;

        int size = adj[curr].size();

        bool isPushed = false;

        for(int i=0; i<size; i++)
        {
            int next = adj[curr][i];
            if(!vis[next])
            {
                q.push(next);
                vis[next] = 1;
                isPushed = true;
            }
            

        }

        if(isPushed) q.push(-1);
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];
    vector<bool> vis(n + 1, 0);

    while(m--)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int shortest = INT_MAX;

    for(int i=1; i<=n; i++)
    {
        int cycleLength = BFS(adj, i, vis);
        shortest = cycleLength == -1 ? : min(shortest, cycleLength);
        vis.assign(n + 1, 0);
    }

    cout << shortest << endl;

    shortest == INT_MAX ? cout << -1 << endl : cout << shortest << endl;

    return 0;
}