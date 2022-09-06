#include <bits/stdc++.h>
using namespace std;

void BFS(vector<int> adj[], vector<int> &parent, vector<bool> &visited, int s, int n)
{
    queue<int> q;
    q.push(s);

    visited[s] = 1;

    while (q.empty() == false)
    {
        int front = q.front();
        q.pop();

        int size = adj[front].size();

        for (int i = 0; i < size; i++)
        {
            if (!visited[adj[front][i]])
            {
                q.push(adj[front][i]);
                parent[adj[front][i]] = front;

                visited[adj[front][i]] = 1;
            }
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

    vector<int> parent(n + 1, -1);
    vector<bool> visited(n + 1, 0);

    BFS(adj, parent, visited, 1, n);

    if(parent[n] == -1)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> ans;

    ans.push_back(n);

    int i = n;

    while (i != 1)
    {
        ans.push_back(parent[i]);
        i = parent[i];
    }

    int s = ans.size();

    cout << s << endl;

    for (int i = s - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }

    return 0;
}