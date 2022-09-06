#include <bits/stdc++.h>
using namespace std;

int dfs(vector<int> adj[], int u, vector<bool> &visited)
{
    visited[u] = 1;

    int size = adj[u].size();

    int ans = 0;

    for (int i = 0; i < size; i++)
    {
        if (!visited[adj[u][i]])
            ans += 1 + dfs(adj, adj[u][i], visited);
    }

    return ans;
}

bool searchDFS(vector<int> adj[], int u, vector<bool> &visited)
{
    visited[u] = 1;

    if(u == 1) return true;

    int n = adj[u].size();

    for(int i=0; i<n; i++)
    {
        int next = adj[u][i];

        if(!visited[next]) return searchDFS(adj, next, visited);
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
    }

    vector<bool> visited(n + 1, 0);

    int depth = 0, start = -1, end = -1;

    bool flag = true;

    depth = dfs(adj, 1, visited);

    if(depth != n - 1)
    {
        flag = false;
        start = 1;

        for(int i=1; i<=n; i++)
        {
            if(!visited[i]) 
            {
                end = i;
                break;
            }
        }
    }
    else
    {
        for(int i=n; i>=2; i--)
        {
            visited.assign(n + 1, 0);
            flag = searchDFS(adj, i, visited);

            if(!flag) 
            {
                start = i;
                end = 1;
                break;
            }
        }

    }
    
    if (flag)
        cout << "YES" << endl;
    else
    {
        cout << "NO" << endl;
        cout << start << " " << end << endl;
    }

    return 0;
}