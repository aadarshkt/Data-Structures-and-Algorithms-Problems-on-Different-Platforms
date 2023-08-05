#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

bool dfs(vector<vector<int>> &adj,int s,int t,vector<int> &vis){
    vis[s]=1;
    if(s==t)return 1;
    int ans=0;
    for(auto i:adj[s]){
        if(!vis[i])ans|=dfs(adj,i,t,vis);
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<int> tar(n),d(n);
    for(auto &x:tar)cin>>x;
    for(auto &x:d)cin>>x;
    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++){
        if(i-d[i]>=0){
            adj[i].push_back(i-d[i]);
            adj[i-d[i]].push_back(i);
        }
        if(i+d[i]<n){
            adj[i].push_back(i+d[i]);
            adj[i+d[i]].push_back(i);
        }
    }
    vector<int> vis(n,0);
    dbg(adj);
    int ans=1;
    for(int i=0;i<n;i++){
        int curr=tar[i]-1,dest=i;
        int res=dfs(adj,curr,dest,vis);
        vis.assign(n,0);
        if(!res){ans=0;break;}
    }
    if(ans)cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';


    return 0;
}