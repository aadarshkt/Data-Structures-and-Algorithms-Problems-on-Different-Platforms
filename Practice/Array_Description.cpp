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
    vector<int> v(n);
    for(auto &x:v)cin>>x;
    vector<vector<int>> dp(n,vector<int>(m+1,0));
    if(v[0]==0){
        for(int i=1;i<=m;i++){
            dp[0][i]=1;
        }
    }else{
        dp[0][v[0]]=1;
    }
    for(int i=1;i<n;i++){
        if(v[i]==0){
            for(int j=1;j<=m;j++){
                if(j-1>=1){
                    (dp[i][j]+=dp[i-1][j-1])%=mod;
                }
                if(j+1<=m){
                    (dp[i][j]+=dp[i-1][j+1])%=mod;
                }
                (dp[i][j]+=dp[i-1][j])%=mod;
            }
        }else{
            int j=v[i];
            if(j-1>=1){
                    (dp[i][j]+=dp[i-1][j-1])%=mod;
                }
                if(j+1<=m){
                    (dp[i][j]+=dp[i-1][j+1])%=mod;
                }
                (dp[i][j]+=dp[i-1][j])%=mod;
        }
    }
    int ans=0;
    for(int j=1;j<=m;j++){
        (ans+=dp[n-1][j])%=mod;
    }
    cout<<ans%mod<<'\n';

    return 0;
}