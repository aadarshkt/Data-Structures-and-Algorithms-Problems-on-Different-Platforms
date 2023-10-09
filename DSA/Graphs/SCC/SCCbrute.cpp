#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

vector<vector<int>> adj;
vector<int> vis;
vector<int> isSCC;//flag to check if a element is in any SCC
vector<vector<int>> ans;

//dfs to find if there is path from x to y
bool isPath(int x,int y){
    vis[x]=1;
    bool res=0;
    for(auto i:adj[x]){
        if(vis[i])continue;
        if(i==y)return true;
        res|=isPath(i,y);
    }
    return res;
}

void findSCC(int n){
    for(int i=1;i<=n;i++){
        if(isSCC[i])continue;
        vector<int> scc;
        scc.push_back(i);
        isSCC[i]=1;
        for(int j=i+1;j<=n;j++){
            if(isSCC[j])continue;
            vis.assign(n+1,0);
            if(isPath(i,j)){
                dbg(i,j);
                vis.assign(n+1,0);
                if(isPath(j,i)){
                    dbg(j,i);
                    scc.push_back(j);
                    isSCC[j]=1;
                }
            }
        }
        ans.push_back(scc);
    }
}


int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;cin>>n>>m;
    adj.resize(n+1);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
    }
    isSCC.resize(n+1,0);
    findSCC(n);
    for(int i=0;i<(int)ans.size();i++){
        for(int j=0;j<(int)ans[i].size();j++){
            cout<<ans[i][j]<<' ';
        }
        cout<<'\n';
    }
    

    return 0;
}