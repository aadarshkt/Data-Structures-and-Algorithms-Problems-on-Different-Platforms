#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

void dfs(vector<vector<int>> &adj,vector<int> &vis,int s,vector<int> &lev){
    vis[s]=1;
    for(auto i:adj[s]){
        if(vis[i])continue;
        lev[i]=lev[s]+1;
        dfs(adj,vis,i,lev);
    }
}

int binaryJump(vector<vector<int>> &dp,int u,int k,int mxJump){
    if(k>(1<<mxJump))return -1;
    int curr=u;
    for(int j=0;(1<<j)<=k;j++){
        if(k&(1<<j)){
            dbg(curr,j,k);
            curr=dp[curr][j];
            dbg(curr,j,k);
        }
        if(curr==-1)break;
    }
    return curr;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;cin>>n>>q;
    vector<int> par(n+1,-1);
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int p;cin>>p;
        par[i+2]=p;
        adj[i+2].push_back(p);
        adj[p].push_back(i+2);
    }
    int mxJump=ceil(log2(n));//in power of 2.
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
    //create levels;
    vector<int> lev(n+1,0),vis(n+1,0);
    dfs(adj,vis,1,lev);
    dbg(lev);
    for(int i=0;i<q;i++){
        int u,v;cin>>u>>v;
        int lv1=lev[u],lv2=lev[v];
        if(lv1<lv2){
            v=binaryJump(dp,v,lv2-lv1,mxJump);
        }else{
            u=binaryJump(dp,u,abs(lv1-lv2),mxJump);
        }
        if(u==v){
            cout<<u<<'\n';
            continue;
        }
        dbg(u,lv1,lv2);
        for(int j=mxJump;j>=0;j--){
           if(dp[u][j]!=dp[v][j])u=dp[u][j],v=dp[v][j];
        }
        cout<<par[u]<<'\n';
    }

    return 0;
}