#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

const int mod=1e9+7;

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;cin>>n>>m;
    vector<vector<int>> dp(m,vector<int>((1<<n),0));
    for(int i=0;i<(1<<n);i++){
        dp[0][i]=1;
    }
    //dp[i][mask] -> number of ways to fill ith column such that which type of block 
    //is used to fill jth row is represented by mask.
    //if 0 then horizontal 1 then vertical.
    //but there is not meaning of mask 101 0 should appear in pairs, 100
    for(int i=1;i<m;i++){
        for(int mask=0;mask<(1<<n);mask++){
            for(int k=0;k<n;k++){

            }
            dp[i-1][mask];
        }
    }

    return 0;
}