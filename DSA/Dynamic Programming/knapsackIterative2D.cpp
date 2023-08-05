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

    int n,W;cin>>n>>W;
    vector<int> val(n),w(n);
    for(auto &x:val)cin>>x;
    for(auto &x:w)cin>>x;
    vector<vector<int>> dp(n,vector<int>(W+1,0));
    for(int j=0;j<W+1;j++){
        if(j-w[0]>=0)dp[0][j]=val[0];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<W+1;j++){
            if(j-w[i]>=0){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+val[i]);
            }else dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n-1][W]<<'\n';


    return 0;
}