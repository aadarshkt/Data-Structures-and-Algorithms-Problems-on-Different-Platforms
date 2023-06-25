#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

void sort(vector<vector<int>> &adj,int s,vector<int> &vis,vector<int> &res){
    vis[s]=1;
    for(int i:adj[s]){
        if(!vis[i]){
            sort(adj,i,vis,res);
        }
    }
    res.push_back(s);
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int> res,vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i])sort(adj,i,vis,res);
    }
    reverse(begin(res),end(res));
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[res[i]]=i;
    }
    int ans=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<(int)adj[i].size();j++){
            if(mp[i]>=mp[adj[i][j]]){
                ans=0;
                break;
            }
        }
    }
    if(!ans)cout<<"IMPOSSIBLE"<<'\n';
    else for(auto x:res)cout<<x<<' ';
    cout<<"\n";

    return 0;
}