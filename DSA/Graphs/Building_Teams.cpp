#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

bool dfs(vector<vector<int>> &adj,int s,vector<int> &dp,vector<int> &vis){
    vis[s]=1;
    int ans=1;
    for(auto i:adj[s]){
        if(!vis[i]){
            dp[i]=!dp[s];
            ans&=dfs(adj,i,dp,vis);
        }else{
            if(dp[s]==dp[i])ans=0;
        }
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n+1,0),dp(n+1,0);
    dp[1]=1;
    int pos=1;
    for(int i=1;i<=n;i++){
        if(!vis[i])pos=dfs(adj,i,dp,vis);
        if(!pos){
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }
    if(pos){
        for(int i=1;i<=n;i++){
            if(dp[i]==1)cout<<1<<' ';
            else cout<<2<<' ';
        }
    }

    return 0;
}