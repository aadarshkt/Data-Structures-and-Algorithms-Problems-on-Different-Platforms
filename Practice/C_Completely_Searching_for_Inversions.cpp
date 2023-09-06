#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

const int mod=998244353;

int cnt=0;
int dfs(vector<vector<pair<int,int>>> &adj,int s,vector<int> &vis,vector<int> &dp){
    vis[s]=1;
    for(auto x:adj[s]){
        if(!vis[i]){
            if(x.second==1){
                dp[s]+=dfs(adj,x.first);
            }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    z.clear();
    int n;cin>>n;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<n;i++){
        int m;cin>>m;
        for(int j=0;j<m;j++){
            int l,w;cin>>l>>w;
            adj[i+1].push_back({l,w});
        }
    }
    dfs(adj,1);
    int n1=z.size();
    vector<int> dp(n1,0);
    int cnt=0;
    for(int i=n1-1;i>=0;i--){
        if(z[i]==0)cnt++;
        else dp[i]=cnt;
    }
    int ans=0;
    for(int i=0;i<n1;i++){
        (ans+=dp[i])%=mod;
    }
    cout<<ans<<'\n';

    return 0;
}