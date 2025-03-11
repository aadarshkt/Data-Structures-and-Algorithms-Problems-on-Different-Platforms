#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int u = q.top().second;
        int d_u = q.top().first;
        q.pop();
        if (d_u != d[u])
            continue;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int len = edge.second;

            if (d[u] + len < d[v]) {
                d[v] = d[u] + len;
                p[v] = u;
                q.push({d[v], v});
            }
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}