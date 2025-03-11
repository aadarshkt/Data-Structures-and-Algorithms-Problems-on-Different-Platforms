#include <bits/stdc++.h>
using namespace std;

#define int long long

void dijkstra(vector<pair<int,int>> adj[], int s, int n){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, s});

    vector<int> dist(n+1, (int)1e18);
    dist[s] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        int d_u = pq.top().first;
        pq.pop();

        if(dist[u] < d_u)
            continue;

        for(auto edge : adj[u]){
            int v = edge.first;
            int len = edge.second;

            if(d_u + len < dist[v]){
                dist[v] = d_u + len;
                pq.push({dist[v], v});
            }
        }
    }


    for(int i = 1; i <= n; i++)cout << dist[i] << ' ';
}



int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> adj[n+1];

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<int> ans;

    dijkstra(adj, 1, n);

    return 0;
}