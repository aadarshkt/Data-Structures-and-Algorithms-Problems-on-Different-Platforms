#include <bits/stdc++.h>
using namespace std;

vector<bool> vis;

int dfs(vector<int> adj[], int u)
{
    vis[u] = 1;

    int n = adj[u].size();

    int ans = 0;

    for(int i=0; i<n; i++)
    {
        int next = adj[u][i];
        if(!vis[next])
        {
            ans += 1 + dfs(adj, next);
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];
    vis.resize(n + 1, 0);

    while(m--)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);

        int count = 0, maxi = 1;

        for(int i=1; i<=n; i++)
        {
            if(!vis[i])
            {
                maxi = max(maxi, 1 + dfs(adj, i));
                count++;
            }
        }

        vis.assign(n + 1, 0);

        cout << count << " " << maxi << endl;

    }




    return 0;
}