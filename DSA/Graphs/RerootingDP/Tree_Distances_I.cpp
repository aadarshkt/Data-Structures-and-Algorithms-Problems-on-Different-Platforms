#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

vector<vector<int>> adj;
vector<int> vis,g,fir,sec;

//dfs call to calculate first and second longest depth.
int dfs1(int s){
    vis[s]=1;
    int ans=0;
    for(int i:adj[s]){
        if(vis[i])continue;
        ans=1+dfs1(i);
        if(ans>=fir[s]){
            sec[s]=fir[s];
            fir[s]=ans;
        }else if(ans>sec[s]){
            sec[s]=ans;
        }
    }
    return ans=fir[s];
}

//dfs call to calculate largest depth going towards parent;
void dfs2(int s){
    vis[s]=1;
    for(auto i:adj[s]){
        if(vis[i])continue;
        if(fir[i]+1==fir[s]){
            g[i]=max(g[s]+1,sec[s]+1);
        }else{
            g[i]=max(g[s]+1,fir[s]+1);
        }
        dbg(i,g[i]);
        dfs2(i);
    }
}


int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    adj.resize(n+1);
    for(int i=0;i<=n;i++)adj[i].clear();
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dbg(adj[1]);
    vis.assign(n+1,0),g.assign(n+1,0),fir.assign(n+1,0),sec.assign(n+1,0);
    dfs1(1);
    vis.assign(n+1,0);
    dfs2(1);
    for(int i=1;i<=n;i++){
        cout<<max(fir[i],g[i])<<' ';
    }
    dbg(fir,g,sec);
    cout<<'\n';


    return 0;
}