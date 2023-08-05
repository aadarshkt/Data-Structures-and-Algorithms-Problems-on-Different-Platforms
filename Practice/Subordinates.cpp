#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int dfs(vector<vector<int>> &adj,int s,vector<int> &dp){
    if(dp[s]>0)return dp[s];
    for(auto i:adj[s]){
        dp[s]+=1+dfs(adj,i,dp);
    }
    return dp[s];
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int x;cin>>x;
        adj[x].push_back(i+2);
    }
    vector<int> dp(n+1,0);
    dp[1]=n-1;
    for(int i=1;i<=n;i++){
        if(dp[i]==0)dfs(adj,i,dp);
    }
    for(int i=1;i<=n;i++)cout<<dp[i]<<' ';

    return 0;
}