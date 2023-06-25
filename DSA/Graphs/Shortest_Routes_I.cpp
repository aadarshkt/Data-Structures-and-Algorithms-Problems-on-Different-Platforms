#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

void build(vector<vector<pair<int,int>>> &adj,vector<int> &dis){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        pair<int,int> fr=pq.top();
        int d=fr.first;
        int u=fr.second;
        pq.pop();
        if(d!=dis[u])continue;
        for(auto i:adj[u]){
            int v=i.first,w=i.second;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                pq.push({dis[v],v});
            }
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    vector<int> dis(n+1,1e18);
    dis[1]=0;
    build(adj,dis);
    for(int i=1;i<=n;i++)cout<<dis[i]<<' ';
    cout<<'\n';

    return 0;
}