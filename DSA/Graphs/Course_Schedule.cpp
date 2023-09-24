#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

//check for cycle and build topo sort
bool dfs(vector<vector<int>> &adj,int s,vector<int> &rec,vector<int> &vis,vector<int> &top){
    rec[s]=1;
    vis[s]=1;
    int ans=0;
    for(auto i:adj[s]){
        if(rec[i]){
            ans=1;break;
        }
        if(vis[i])continue;
        ans|=dfs(adj,i,rec,vis,top);
        if(ans==1)break;
    }
    top.push_back(s);
    rec[s]=0;
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
    }
    vector<int> rec(n+1,0),top,vis(n+1,0);
    bool isCyc=0;
    for(int i=1;i<=n;i++){
        if(!vis[i])isCyc=dfs(adj,i,rec,vis,top);
        if(isCyc)break;
    }
    if(isCyc)cout<<"IMPOSSIBLE"<<'\n';
    else{
        reverse(begin(top),end(top));
        for(int x:top)cout<<x<<' ';
    }


    return 0;
}