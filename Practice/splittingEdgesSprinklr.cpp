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

bool check3(int s,vector<int> &val){
    vis[s]=1;
    if(val[s]==3)return true;
    bool ans=false;
    for(auto i:adj[s]){
        if(vis[i])continue;
        ans|=check3(i,val);
    }
    return ans;
}

bool check2(int s,vector<int> &val){
    vis[s]=1;
    if(val[s]==2)return true;
    bool ans=false;
    for(auto i:adj[s]){
        if(vis[i])continue;
        ans|=check2(i,val);
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;cin>>t;
    for(int tt=0;tt<t;tt++){
        int n;cin>>n;
        vector<int> a(n);
        for(auto &x:a)cin>>x;
        vis.assign(n+1,0);
        adj.resize(n+1);
        for(int i=0;i<=n;i++)adj[i].clear();
        vector<pair<int,int>> e;
        for(int i=0;i<n-1;i++){
            int u,v;cin>>u>>v;
            e.push_back({u,v});
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            vis.assign(n+1,0);
            bool is3=check3(i,a);
            vis.assign(n+1,0);
            bool is2=check2(i,a);
            if(is2&&is3)dp[i]=1;
        }
        int ans=0;
        for(auto i:e){
            dbg(i);
            if(!dp[i.first]&&!dp[i.second]){
                ans++;
            }
        }
        cout<<ans<<'\n';


    }

    return 0;
}