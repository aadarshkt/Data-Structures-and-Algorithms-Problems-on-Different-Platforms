#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

void dfs(vector<vector<int>> &adj,int s,vector<int> &vis,vector<int> &par){
    vis[s]=1;
    for(auto i:adj[s]){
        if(!vis[i]){
            par[i]=s;
            dfs(adj,i,vis,par);
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,r1,r2;cin>>n>>r1>>r2;
    vector<int> p1(n+1),p2(n+1);
    p1[r1]=-1;
    for(int i=1;i<=n;i++){
        if(i!=r1)cin>>p1[i];
    }
    vector<vector<int>> adj(n+1);
    for(int i=1;i<=n;i++){
        if(i!=r1){
            adj[i].push_back(p1[i]);
            adj[p1[i]].push_back(i);
        }
    }
    p2[r2]=-1;
    vector<int> vis(n+1,0);
    dfs(adj,r2,vis,p2);
    for(int i=1;i<=n;i++){
        if(i!=r2)cout<<p2[i]<<' ';
    }


    return 0;
}