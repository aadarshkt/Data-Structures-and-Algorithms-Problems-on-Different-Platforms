#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

void bfs(vector<vector<int>> &adj,vector<int> &vis,vector<int> &dis,int s,int n){
    vis[s]=1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int fr=q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                if(!adj[fr][i])continue;
                vis[i]=1;
                dis[i]=dis[fr]+1;
                q.push(i);
            }
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,s,t;cin>>n>>m>>s>>t;
    vector<vector<int>> adj(n+1,vector<int>(n+1,0));
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    vector<int> vis(n+1,0);
    vector<int> diss(n+1,0),dist(n+1,0);
    bfs(adj,vis,diss,s,n);
    vis.assign(n+1,0);
    bfs(adj,vis,dist,t,n);
    dbg(diss,dist,diss[t]);
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            //third condition was left.
            if(diss[i]+dist[j]+1>=diss[t]&&!adj[i][j]&&diss[j]+dist[i]+1>=diss[t]){
                dbg(i,j);
                ans++;
            }
        }
    }
    dbg(ans);
    cout<<ans<<"\n";
    


    return 0;
}