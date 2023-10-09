#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

vector<int> lv,vis,dp;
vector<vector<int>> adj;

//dp[i] --> minimum lvel(or highest lvel) that node u can connect to.
//idea --> a edge is bridge is there is no node in subtree of u that can connect a lvel higher or equal to u.


int dfs(int s){
    vis[s]=1;
    dp[s]=lv[s];
    for(auto i:adj[s]){
        if(vis[i]){
            dp[s]=min(dp[s],lv[i]);
            continue;
        }
        lv[i]=lv[s]+1;
        dp[s]=min(dfs(i),lv[s]);
        //dp[i] would be completely calculated if dfs(i) is called.
        //one way is this or you can simply iterate on edges also. as give below.
        if(dp[i]>lv[s]){
            //bridge edge.
            cout<<s<<' '<<i<<'\n';
        }
    }
    return dp[s];
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;cin>>n>>m;
    lv.assign(n+1,0),vis.assign(n+1,0),dp.assign(n+1,INT_MAX);
    adj.resize(n+1);
    for(int i=0;i<=n;i++)adj[i].clear();
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i])dfs(i);
    }
    //second way
    //but multiple caculation
    for(int i=1;i<=n;i++){
        for(int x:adj[i]){
            if(dp[x]>dp[i]){
                cout<<"bridge is "<<i<<' '<<x<<'\n';
            }
        }
    }
    

    return 0;
}