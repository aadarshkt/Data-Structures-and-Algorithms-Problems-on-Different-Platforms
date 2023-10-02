#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

//find whether a graph is SCC or not in O(n)
//idea explained in idea.txt

vector<int> vis;

void dfs(int s,vector<vector<int>> &adj1){
    vis[s]=1;
    for(int i:adj1[s]){
        if(vis[i])continue;
        dfs(i,adj1);
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;cin>>n>>m;
    vector<vector<int>> adj1(n+1),adj2(n+1);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj1[u].push_back(v);
        adj2[v].push_back(u);
    }
    vis.assign(n+1,0);
    dfs(1,adj1);
    int isSCC=1;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            isSCC=0;break;
        }
    }
    if(isSCC){
        vis.assign(n+1,0);
        dfs(1,adj2);
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                isSCC=0;break;
            }
        }
    }
    if(isSCC)cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';



    return 0;
}