#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

//1. Find LCA
//2. Level difference of two node with LCA
//3. Sum them.

//Find levels
void dfs(vector<vector<int>> &adj,vector<int> &vis,vector<int> &lev,vector<int> &par,int s){
    vis[s]=1;
    for(auto i:adj[s]){
        if(vis[i])continue;
        lev[i]=lev[s]+1;
        par[i]=s;
        dfs(adj,vis,lev,par,i);
    }
}

//find lca 
//1. bring both node to same level
//2. now find maximum jump that you can jump to get to not equal ancestor.
//3. parent of that is lca.
//4. for second point use int k=0 start from mxJump (pow of 2)

int binaryJump(vector<vector<int>> &dp,int u,int k,int n){
    int mxJump=ceil(log2(n));
    if(k>(1<<mxJump))return -1;
    int curr=u;
    for(int j=0;j<=mxJump;j++){
        if(k&(1<<j)){
            curr=dp[curr][j];
        }
        if(curr==-1)break;
    }
    return curr;
}

int lca(int a,int b,vector<vector<int>> &dp,vector<int> &lev,int n,vector<int> &par){
    int mxJump=ceil(log2(n));
    int lv1=lev[a],lv2=lev[b];
    if(lv1<lv2)swap(a,b);//a is at more depth
    a=binaryJump(dp,a,abs(lv1-lv2),n);//now at same level
    if(a==b)return a;
    for(int j=mxJump;j>=0;j--){
        if(dp[a][j]!=dp[b][j])a=dp[a][j],b=dp[b][j];
    }
    return par[a];
}


int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;cin>>n>>q;
    vector<int> par(n+1,-1);
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //build the level array
    vector<int> vis(n+1,0),lev(n+1,0);
    dfs(adj,vis,lev,par,1);
    //precomputing for every node what comes if we jump powers of 2.
    int mxJump=ceil(log2(n));
    vector<vector<int>> dp(n+1,vector<int>(mxJump+1,-1));
    //base case
    for(int i=1;i<=n;i++){
        dp[i][0]=par[i];
    }
    for(int j=1;j<=mxJump;j++){
        for(int i=1;i<=n;i++){
            if(dp[i][j-1]!=-1)
                dp[i][j]=dp[dp[i][j-1]][j-1];
        }
    }
    //answer queries
    for(int i=0;i<q;i++){
        int a,b;cin>>a>>b;
        int lcnode=lca(a,b,dp,lev,n,par);
        if(lcnode<0)cout<<"are baap re"<<'\n';
        cout<<abs(lev[a]-lev[lcnode])+abs(lev[b]-lev[lcnode])<<'\n';
    }

    return 0;
}