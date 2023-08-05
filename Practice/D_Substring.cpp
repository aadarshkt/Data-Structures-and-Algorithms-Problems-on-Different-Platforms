#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

bool detectCycle(vector<set<int>> &adj,vector<int> &vis,int s,vector<int> &rec){
    vis[s]=1;
    rec[s]=1;
    int ans=0;
    for(auto i:adj[s]){
        if(rec[i])ans=1;
        if(!vis[i]){
            ans|=detectCycle(adj,vis,i,rec);
        }
    }
    rec[s]=0;
    return ans;
}

void topo(vector<set<int>> &adj,vector<int> &vis,int s,vector<int> &res){
    vis[s]=1;
    for(auto i:adj[s]){
        if(vis[i])continue;
        topo(adj,vis,i,res);
    }
    res.push_back(s);
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;cin>>n>>m;
    string s;cin>>s;
    vector<set<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].insert(v);
    }
    vector<int> vis(n+1,0),rec(n+1,0);
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        bool isCyc=detectCycle(adj,vis,i,rec);
        if(isCyc){
            cout<<-1<<'\n';
            return 0;
        }
    }
    vector<int> sorted;
    vis.assign(n+1,0);
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        topo(adj,vis,i,sorted);
    }
    vector<int> f(26,0);
    for(int j=0;j<26;j++){
        char c='a'+j;
        vector<int> dp(n+1,0);
        for(auto x:sorted){
            int cnt=0;
            for(auto i:adj[x]){
                cnt=max(cnt,dp[i]);
            }
            dp[x]+=cnt;
            if(s[x-1]==c)dp[x]++;
        }
        f[j]=*max_element(begin(dp),end(dp));
    }
    int ans=0;
    ans=*max_element(begin(f),end(f));
    cout<<ans<<'\n';


    return 0;
}