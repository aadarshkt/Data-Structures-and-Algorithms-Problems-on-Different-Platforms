#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

void dfs(vector<vector<int>> &adj,vector<int> &vis,vector<int> &par,int s){
    vis[s]=1;
    for(auto i:adj[s]){
        if(vis[i])continue;
        par[i]=s;
        dfs(adj,vis,par,i);
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int mxJump=ceil(log2(n-1));
    vector<int> vis(n+1,0),par(n+1,-1);
    dfs(adj,vis,par,1);
    //binary lifting precomputation
    //for every node i what comes if we jump 1<<j represented by dp[i][j]
    vector<vector<int>> dp(n+1,vector<int>(mxJump+1,-1));
    for(int i=1;i<=n;i++){
        dp[i][0]=par[i];
    }
    for(int j=1;j<=mxJump;j++){
        for(int i=1;i<=n;i++){
            if(dp[i][j-1]!=-1)
                dp[i][j]=dp[dp[i][j-1]][j-1];
        }
    }
    int q;cin>>q;
    for(int i=0;i<q;i++){
        int u,k;cin>>u>>k;
        int curr=u;
        for(int j=0;j<=32;j++){
            if(k&(1<<j)){
                curr=dp[curr][j];
            }
            if(curr==-1)break;
        }
        cout<<curr<<'\n';
    }

    return 0;
}