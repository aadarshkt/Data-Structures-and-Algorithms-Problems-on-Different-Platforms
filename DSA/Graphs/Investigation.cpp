#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

const int mod=1e9+7;

void build(vector<vector<pair<int,int>>> &adj,vector<int> &dis,vector<int> &mx,vector<int> &mn,vector<int> &ways){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        pair<int,int> fr=pq.top();
        int u=fr.second,d=fr.first;
        pq.pop();
        if(d!=dis[u])continue;
        for(auto i:adj[u]){
            int v=i.first,w=i.second;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                (ways[v]=ways[u])%=mod;
                mx[v]=1+mx[u];
                mn[v]=1+mn[u];
                pq.push({dis[v],v});
            }else if(dis[v]==dis[u]+w){
                (ways[v]+=ways[u])%=mod;
                if(mx[v]<1+mx[u])mx[v]=1+mx[u];
                if(mn[v]>1+mn[u])mn[v]=1+mn[u];
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
    vector<int> dis(n+1,LLONG_MAX),mx(n+1,LLONG_MIN),mn(n+1,LLONG_MAX),ways(n+1,0);
    dis[1]=0,mx[1]=0,mn[1]=0,ways[1]=1;
    build(adj,dis,mx,mn,ways);
    cout<<dis[n]<<' '<<ways[n]<<' '<<mn[n]<<' '<<mx[n];

    return 0;
}