#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long


vector<vector<int>> dp;

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //find maximum value such that no common node is reached.
    int k = 0;//correct of amount of jump needed to reach LCA

    int u,v;cin>>u>>v;

    //after same level is reached.
    for(int i=30;i>=0;i--){
        if(dp[u][i]!=dp[v][i]){
            k = k|(1<<i);
        }
    }

    cout<<dp[u][k]<<'\n';
    

    return 0;
}