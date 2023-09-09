#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int dp[(int)2e5+1][31];

void dfs(vector<vector<int>> &adj,vector<int> &vis,vector<int> &lev,vector<int> &par,int s){
    vis[s]=1;
    for(auto i:adj[s]){
        if(vis[i])continue;
        lev[i]=lev[s]+1;
        par[i]=s;
        dfs(adj,vis,lev,par,i);
    }
}

int binaryJump(int u,int k){
    int curr=u;
    for(int j=0;(1<<j)<=k;j++){
        if(k&(1<<j)){
            curr=dp[curr][j];
        }
        if(curr==-1)break;
    }
    return curr;
}

int lca(int a,int b,vector<int> &lev,vector<int> &par){
    int lv1=lev[a],lv2=lev[b];
    if(lv1<lv2)swap(a,b);
    a=binaryJump(a,abs(lv1-lv2));
    if(a==b)return a;
    for(int j=30;j>=0;j--){
        if(dp[a][j]!=dp[b][j])a=dp[a][j],b=dp[b][j];
    }
    return par[a];
}

int simple_dfs(vector<vector<int>> &adj,int s,vector<int> &vis,vector<int> &pre){
    vis[s]=1;
    for(auto i:adj[s]){
        if(vis[i])continue;
        pre[s]+=simple_dfs(adj,i,vis,pre);
    }
    return pre[s];
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //build the level and parent vector
    vector<int> vis(n+1,0),lev(n+1,0),par(n+1,-1);
    dfs(adj,vis,lev,par,1);

    memset(dp,-1,sizeof(dp));
    //dp[i][j] --> starting from node i what is there after 1<<j jumps.
    //base case.
    for(int i=1;i<=n;i++){
        dp[i][0]=par[i];
    }
    for(int j=1;j<=30;j++){
        for(int i=1;i<=n;i++){
            if(dp[i][j-1]!=-1)
                dp[i][j]=dp[dp[i][j-1]][j-1];
        }
    }

    //we will make both node just below lca to 1 and both node below a b to -1, then apply
    //prefix to dfs;
    vector<int> pre(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        pre[a]++,pre[b]++;
        int v=lca(a,b,lev,par);
        pre[v]--;
        if(v!=1)pre[par[v]]--;
    }
    vis.assign(n+1,0);
    simple_dfs(adj,1,vis,pre);
    for(int i=1;i<=n;i++)cout<<pre[i]<<' ';
    return 0;
}