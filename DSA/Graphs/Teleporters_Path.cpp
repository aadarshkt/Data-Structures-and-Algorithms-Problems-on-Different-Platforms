#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;cin>>n>>m;
    vector<vector<int>> adj(n,vector<int>(n,0));
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        u--,v--;
        adj[u][v]=1;
    }
    vector<int> par(n,-1);
    vector<vector<int>> dp(n,vector<int>((1<<n),0));
    //dp[i][mask] --> whether or not you can reach at i visiting rest vertices(according to mask) exactly once.
    for(int i=0;i<n;i++){
        dp[i][1<<i]=1;
    }
    for(int mask=2;mask<(1<<n);mask++){
        if((mask&1)==0)continue;
        if(mask&(1<<(n-1))&&mask!=((1<<n)-1))continue;
        for(int j=0;j<n;j++){
            if(!(mask&(1<<j)))continue;
            for(int k=0;k<n;k++){
                if(!(mask&(1<<k)))continue;
                if(j==k)continue;
                if(!adj[k][j])continue;
                if(dp[k][mask^(1<<j)]){
                    dp[j][mask]=1;
                    par[j]=k;
                    break;
                }
            }
        }
    }
    if(dp[n-1][(1<<n)-1]){
        vector<int> path;
        path.push_back(n);
        int p=par[n-1];
        while(p!=-1){
            path.push_back(p+1);
            p=par[p];
        }
        for(int i=(int)path.size()-1;i>=0;i--){
            cout<<path[i]<<' ';
        }
    }else cout<<"IMPOSSIBLE"<<'\n';

    return 0;
}