#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int>> adj;
vector<int> vis,dp,a,ans;

int dfs1(int s){
    vis[s]=1;
    dp[s]=a[s]==1?1:-1;
    for(auto i:adj[s]){
        if(vis[i])continue;
        dp[s]+=max((long long)0,dfs1(i));
    }
    return dp[s];
}

void dfs2(int s){
    vis[s]=1;
    for(int i:adj[s]){
        if(vis[i])continue;
        dp[s]-=max((long long)0,dp[i]);
        dp[i]+=max((long long)0,dp[s]);
        ans[i]=dp[i];
        dfs2(i);
        dp[i]-=max((long long)0,dp[s]);
        dp[s]+=max((long long)0,dp[i]);
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    a.assign(n+1,0);
    ans.assign(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    adj.assign(n+1,{});
    vis.assign(n+1,0);
    dp.assign(n+1,0);
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1);
    ans[1]=dp[1];
    vis.assign(n+1,0);
    dfs2(1);
    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';


    return 0;
}