#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

vector<int> adj[(int)1e6];
vector<int> vis((int)1e6);

int dfs(int s,int &n){
    vis[s]=1;
    int ans=0;
    int fl=0;
    for(auto i:adj[s]){
        if(vis[i])continue;
        fl=1;
        int node=-1;
        int depth=1+dfs(i,node);
        if(depth>=ans){
            ans=depth;
            n=node;
        }
    }
    if(!fl)n=s;
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vis.clear();
    for(int i=0;i<(int)1e6;i++)adj[i].clear();
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int node=0;
    dfs(1,node);
    for(int i=0;i<(int)1e6;i++)vis[i]=0;
    int dia=dfs(node,node);
    cout<<dia<<'\n';

    return 0;
}