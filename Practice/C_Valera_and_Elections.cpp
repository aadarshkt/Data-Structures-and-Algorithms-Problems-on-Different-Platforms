#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int dfs(vector<vector<pair<int,int>>> &adj,vector<int> &vis,vector<int> &dp,int s,vector<int> &idx){
    vis[s]=1;
    for(auto &i:adj[s]){
        int v=i.first,r=i.second;
        if(!vis[v]){
            int can=dfs(adj,vis,dp,v,idx);
            if(can==0){
                if(r==2){
                    dp[s]+=1;
                    idx.push_back(v);
                }
            }else dp[s]+=can;
        }
    }
    return dp[s];
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v,r;cin>>u>>v>>r;
        adj[u].push_back({v,r});
        adj[v].push_back({u,r});
    }
    vector<int> dp(n+1,0),vis(n+1,0),idx;
    dfs(adj,vis,dp,1,idx);
    cout<<dp[1]<<'\n';
    for(auto x:idx)cout<<x<<' ';

    return 0;
}