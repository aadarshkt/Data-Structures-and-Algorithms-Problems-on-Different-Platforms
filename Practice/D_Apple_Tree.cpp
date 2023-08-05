#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int dfs(vector<vector<int>> &adj,vector<int> &vis,int s,vector<int> &dp){
    vis[s]=1;
    if((int)adj[s].size()==1&&vis[adj[s][0]]==1)return dp[s]=1;
    for(auto i:adj[s]){
        if(!vis[i]){
            dp[s]+=dfs(adj,vis,i,dp);
        }
    }
    return dp[s];
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;cin>>n;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n-1;i++){
            int u,v;cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n+1,0),dp(n+1,0);
        dfs(adj,vis,1,dp);
        int q;cin>>q;
        for(int i=0;i<q;i++){
            int x,y;cin>>x>>y;
            int w1=dp[x],w2=dp[y];
            cout<<w1*w2<<'\n';
        }

    }

    return 0;
}