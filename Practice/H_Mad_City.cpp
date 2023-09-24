#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

void dfs(vector<vector<int>> &adj,int s,vector<int> &vis,vector<int> &par,int &depth,int d){
    vis[s]=1;
    for(auto i:adj[s]){
        if(vis[i]&&i!=par[s]){
            if(depth==0)depth=d;
        }
        if(vis[i])continue;
        par[i]=s;
        dfs(adj,i,vis,par,depth,d+1);
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n,a,b;cin>>n>>a>>b;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n;i++){
            int u,v;cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n+1,0),par(n+1,-1);
        int disa=0,disb=0;
        dfs(adj,a,vis,par,disa,0);
        dbg(a,b,vis,par,disa);
        vis.assign(n+1,0),par.assign(n+1,-1);
        dfs(adj,b,vis,par,disb,0);
        dbg(disa,disb);
        if(disa>=disb){
            if(a==b)cout<<"NO"<<'\n';
            else cout<<"YES"<<'\n';
        }else cout<<"NO"<<'\n';
    }

    return 0;
}