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

    int n;cin>>n;
    vector<vector<int>> co(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>co[i][j];
        }
    }
    vector<int> dp((1<<n),0);
    dp[0]=1;
    //dp[mask] --> number of ways set bits female can be paired with first |s| males.
    for(int i=0;i<n;i++){
        for(int mask=1;mask<(1<<n);mask++){
            int setbits=__builtin_popcount(mask);
            if(setbits!=i+1)continue;
            for(int j=0;j<n;j++){
                if(!co[i][j]||!(mask&(1<<j)))continue;
                (dp[mask]+=dp[mask^(1<<j)])%=mod;
            }
        }
    }
    cout<<dp[(1<<n)-1]<<'\n';

    return 0;
}