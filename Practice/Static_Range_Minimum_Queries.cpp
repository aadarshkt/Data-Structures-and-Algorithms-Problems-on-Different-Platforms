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

    int n,q;cin>>n>>q;
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    int mxPow=ceil(log2(n));
    vector<vector<int>> dp(n,vector<int>(mxPow+1,INT_MAX));
    for(int i=0;i<n;i++){
        dp[i][0]=a[i];
    }
    //dp[i][j] --> standing at i what is minimum of the interval [i,i+(1<<j)-1];
    for(int j=1;j<=mxPow;j++){
        for(int i=0;i+(1<<j)-1<n;i++){
            dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
        }
    }
    //answer the queries
    for(int i=0;i<q;i++){
        int l,r;cin>>l>>r;
        l--,r--;
        int len=r-l+1;
        int k=log2(len);//pow of 2 less than or equal to length.
        cout<<min(dp[l][k],dp[r-(1<<k)+1][k])<<'\n';
    }

    return 0;
}