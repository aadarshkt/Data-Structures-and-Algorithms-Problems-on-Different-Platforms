#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int maxDepth(vector<vector<int>> &adj,int s,vector<int> &vis){
    vis[s]=1;
    int ans=0;
    for(auto i:adj[s]){
        if(vis[i])continue;
        ans=max(ans,1+maxDepth(adj,i,vis));
    }
    return ans;
}

int bfs(vector<vector<int>> &adj,int s,vector<int> &vis){
    vis[s]=1;
    queue<int> q;
    q.push(s);
    int node=1;
    while(!q.empty()){
        int fr=q.front();
        q.pop();
        node=fr;
        for(auto i:adj[fr]){
            if(vis[i])continue;
            vis[i]=1;
            q.push(i);
        }
    }
    return node;
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
    int maxDepthNode=bfs(adj,1,vis);
    dbg(maxDepthNode);
    vis.assign(n+1,0);
    int maxD=maxDepth(adj,maxDepthNode,vis);
    cout<<maxD<<'\n';



    return 0;
}