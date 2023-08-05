#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

void topo(vector<vector<int>> &adj,vector<int> &vis,int s,vector<int> &res){
    vis[s]=1;
    for(auto i:adj[s]){
        if(vis[i])continue;
        topo(adj,vis,i,res);
    }
    res.push_back(s);
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,c,m;cin>>n>>c>>m;
    vector<vector<int>> adj(n+1);
    vector<int> ches(n+1,0);
    for(int i=0;i<c;i++){
        int node;cin>>node;
        ches[node]=1;
    }
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int> vis(n+1,0),sorted;
    for(int i=1;i<=n;i++){
        if(!vis[i])topo(adj,vis,i,sorted);
    }
    vector<pair<int,int>> ans(n+1,{INT_MIN,INT_MAX});
    reverse(begin(sorted),end(sorted));
    if(ches[1]){
        ans[1].first=max((long long)1,ans[1].first);
        ans[1].second=min((long long)1,ans[1].second);
    }else{
        ans[1].first=max((long long)0,ans[1].first);
        ans[1].second=min((long long)0,ans[1].second);
    }
    dbg(sorted);
    for(auto x:sorted){
        for(auto i:adj[x]){
            if(ches[i]){
                ans[i].first=max((long long)1+ans[x].first,ans[i].first);
                ans[i].second=min((long long)1+ans[x].second,ans[i].second);
            }else{
                ans[i].first=max((long long)0+ans[x].first,ans[i].first);
                ans[i].second=min((long long)0+ans[x].second,ans[i].second);
            }
        }
    }
    cout<<ans[n].second<<' '<<ans[n].first<<"\n";

    return 0;
}