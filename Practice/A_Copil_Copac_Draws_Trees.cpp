#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int DFS(vector<vector<pair<int,int>>> &adj,vector<int> &vis,int s,int idx){
    vis[s]=1;
    int ans=0;
    for(auto i:adj[s]){
        if(vis[i.first])continue;
        if(i.second>idx)ans=max(ans,DFS(adj,vis,i.first,i.second));
        else ans=max(ans,1+DFS(adj,vis,i.first,i.second));
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;cin>>n;
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<n-1;i++){
            int a,b;cin>>a>>b;
            adj[a].push_back({b,i});
            adj[b].push_back({a,i});
        }
        vector<int> vis(n+1,0);
        cout<<1+DFS(adj,vis,1,-1)<<'\n';
    }

    return 0;
}