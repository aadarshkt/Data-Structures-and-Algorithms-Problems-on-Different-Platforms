#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int dfs(vector<vector<int>> &adj,vector<int> &vis,int s,int &mx,int &smx){
    vis[s]=1;
    int ans=0;
    for(auto i:adj[s]){
        if(vis[i])continue;
        ans=max(ans,1+dfs(adj,vis,i,mx,smx));
        if(ans>=mx){
            smx=mx;
            mx=ans;
        }
    }
    return ans;
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
    vector<int> vis(n+1,0);
    int mx=0,smx=0;
    mx=dfs(adj,vis,1,mx,smx);
    cout<<mx+smx<<'\n';

    return 0;
}