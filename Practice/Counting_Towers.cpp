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

    int t;
    cin >> t;
    while(t--){
        int n;cin>>n;
        int dp[n+1][2];
        memset(dp,0,sizeof(dp));
        dp[1][0]=1,dp[1][1]=1;
        for(int i=2;i<=n;i++){
            (dp[i][0]=4*dp[i-1][0]+dp[i-1][1])%=mod;
            (dp[i][1]=2*dp[i-1][1]+dp[i-1][0])%=mod;
        }
        cout<<(dp[n][0]+dp[n][1])%mod<<'\n';
    }

    return 0;
}