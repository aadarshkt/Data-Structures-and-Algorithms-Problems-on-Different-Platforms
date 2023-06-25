#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

void dij(vector<vector<pair<int,int>>> &adj,vector<int> &dis,int s){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        pair<int,int> fr=pq.top();
        int d=fr.first,u=fr.second;
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
    vector<vector<pair<int,int>>> adj(n+1),rev(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        adj[u].push_back({v,w});
        rev[v].push_back({u,w});
    }
    vector<int> dis1(n+1,1e18),dis2(n+1,1e18);
    dis1[1]=0,dis2[n]=0;
    dij(adj,dis1,1);
    dij(rev,dis2,n);
    int ans=1e18;
    for(int i=1;i<=n;i++){
        for(auto edge:adj[i]){
            int u=i,v=edge.first,w=edge.second;
            ans=min(ans,dis1[u]+w/2+dis2[v]);
        }
    }
    cout<<ans<<'\n';

    return 0;
}