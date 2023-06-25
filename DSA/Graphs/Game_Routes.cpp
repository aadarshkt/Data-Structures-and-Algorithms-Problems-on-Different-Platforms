#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

const int mod=1e9+7;

bool dfs(vector<vector<int>> &adj,vector<int> &vis,vector<int> &rec,int s,vector<int> &top){
    vis[s]=1;
    rec[s]=1;
    int ans=0;
    for(auto i:adj[s]){
        if(rec[i])ans=1;
        if(!vis[i]){
            ans|=dfs(adj,vis,rec,i,top);
        }
    }
    top.push_back(s);
    rec[s]=0;
    return ans;
}

void relax(vector<vector<int>> &adj,vector<int> &parent,vector<int> &dp,int s){
    for(auto i:adj[s]){
        (dp[i]+=dp[s])%=mod;
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> vis(n+1,0),parent(n+1,-1),rec(n+1,0),top,dp(n+1,0);
    dp[1]=1;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(adj,vis,rec,i,top);
        }
    }
    reverse(begin(top),end(top));
    for(auto x:top){
        relax(adj,parent,dp,x);
    }
    cout<<dp[n]<<'\n';

    return 0;
}