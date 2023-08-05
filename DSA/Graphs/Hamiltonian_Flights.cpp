#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

const int mod=1e9+7;

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;cin>>n>>m;
    vector<vector<int>> adj(n),f(n,vector<int>(n,0));
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        u--,v--;
        if(!f[u][v]){
            adj[u].push_back(v);
            f[u][v]=1;
        }else f[u][v]++;
    }
    vector<vector<int>> dp(n,vector<int>((1<<n),0));
    //dp[i][mask] --> number of hamiltonian paths ending at node i, given mask.
    //setbits in mask represents current nodes.
    dp[0][1]=1;
    for(int mask=2;mask<(1<<n);mask++){
        //for every pair of set bits.
        if((mask&1)==0)continue;
        if(mask&(1<<(n-1))&&mask!=((1<<n)-1))continue;
        for(int k=0;k<n;k++){
            if(!(mask&(1<<k)))continue;
            for(auto j:adj[k]){
                if(!(mask&(1<<j)))continue;
                (dp[j][mask]+=(f[k][j]*dp[k][mask^(1<<j)])%mod)%=mod;
            }
        }
    }
    cout<<dp[n-1][(1<<n)-1]%mod<<'\n';

    return 0;
}