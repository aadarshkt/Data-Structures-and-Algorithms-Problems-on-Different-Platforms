#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

void bfs(vector<vector<int>> &adj,vector<int> &vis,vector<int> &indeg,int s,vector<int> &res,queue<int> &q){
    while(!q.empty()){
        int fr=q.front();
        q.pop();
        res.push_back(fr);
        for(auto i:adj[fr]){
            if(!vis[i]){
                vis[i]=1;
                indeg[i]--;
                if(indeg[i]==0)q.push(i);
            }
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> indeg(n+1,0);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    queue<int> q;
    vector<int> vis(n+1,0),res;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            q.push(i);
            vis[i]=1;
        }
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            bfs(adj,vis,indeg,i,res,q);
        }
    }

    map<int,int> mp;
    for(int i=0;i<(int)res.size();i++){
        mp[res[i]]=i;
    }
    //check
    int ans=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<(int)adj[i].size();j++){
            if(mp[i]>=mp[adj[i][j]]){
                ans=0;
                break;
            }
        }
    }
    if(ans){
        for(auto x:res)cout<<x<<" ";
    }else cout<<"IMPOSSIBLE"<<"\n";

    return 0;
}