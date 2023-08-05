#include <bits/stdc++.h>
using namespace std;

#define int long long

bool bfs(vector<vector<int>> &adj,vector<int> &vis,int s,int t,vector<int> &par){
    vis[s]=1;
    queue<int> q;
    q.push(s);
    int ans=0;
    while(!q.empty()){
        int fr=q.front();
        q.pop();
        for(auto i:adj[fr]){
            if(!vis[i]){
                par[i]=fr;
                vis[i]=1;
                if(i==t){
                    ans=1;
                    break;
                }
                q.push(i);
            }
        }
        if(ans)break;
    }
    return ans;
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
        adj[v].push_back(u);
    }
    vector<int> vis(n+1,0),par(n+1,-1);
    int ans=bfs(adj,vis,1,n,par);
    if(ans){
        vector<int> path;
        path.push_back(n);
        int s=n;
        s=par[s];
        while(s!=-1){
            path.push_back(s);
            s=par[s];
        }
        reverse(begin(path),end(path));
        cout<<path.size()<<'\n';
        for(auto x:path)cout<<x<<' ';
    }else cout<<"IMPOSSIBLE"<<'\n';

    return 0;
}