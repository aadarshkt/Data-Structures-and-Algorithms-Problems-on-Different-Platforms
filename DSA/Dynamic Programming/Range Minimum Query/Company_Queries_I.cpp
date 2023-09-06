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

    int n,q;cin>>n>>q;
    vector<int> par(n+1,-1);
    for(int i=0;i<n-1;i++){
        int p;cin>>p;
        par[i+2]=p;
    }
    int mxJump=ceil(log2(n-1));
    vector<vector<int>> dp(n+1,vector<int>(mxJump+1,-1));
    for(int i=1;i<=n;i++){
        dp[i][0]=par[i];
    }
    for(int j=1;j<=mxJump;j++){
        for(int i=1;i<=n;i++){
            if(dp[i][j-1]!=-1&&dp[dp[i][j-1]][j-1]!=-1)
                dp[i][j]=dp[dp[i][j-1]][j-1];
        }
    }
    dbg(par,dp);
    for(int i=0;i<q;i++){
        int x,k;cin>>x>>k;
        int curr=x;
        if(k>(1<<mxJump)){
            cout<<-1<<'\n';
            continue;
        }
        for(int j=0;(1<<j)<=k;j++){
            if(k&(1<<j)){
                dbg(i,curr,j);
                curr=dp[curr][j];
            }
            if(curr==-1)break;
        }
        cout<<curr<<'\n';
    }

    return 0;
}