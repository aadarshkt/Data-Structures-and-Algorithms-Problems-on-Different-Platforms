#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

void dij(vector<vector<pair<int,int>>> &adj,vector<vector<int>> &dis,int s,int k){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        pair<int,int> fr=pq.top();
        int d=fr.first,u=fr.second;
        pq.pop();
        if(d!=dis[u][0])continue;
        for(auto i:adj[u]){
            int v=i.first,w=i.second;
            if(dis[v][0]>=dis[u][0]+w){
                dis[v].push_back(dis[u][0]+w);
                sort(begin(dis[v]),end(dis[v]));
                if((int)dis[v].size()>k){
                    dis[v].pop_back();
                }
                pq.push({dis[v][0],v});
            }else{
                dis[v].push_back(dis[u][0]+w);
                sort(begin(dis[v]),end(dis[v]));
                if((int)dis[v].size()>k){
                    dis[v].pop_back();
                } 
            }
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,k;cin>>n>>m>>k;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    vector<vector<int>> dis(n+1);
    dis[1].push_back(0);
    for(int i=2;i<=n;i++){
        dis[i].push_back(1e18);
    }
    dij(adj,dis,1,k);
    for(auto x:dis[n]){
        cout<<x<<' ';
    }

    return 0;
}