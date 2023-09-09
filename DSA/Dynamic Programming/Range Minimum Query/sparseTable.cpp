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

    int n;cin>>n;
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    //dp[i][j] --> minimum of interval starting at index i and having length 1<<j;
    int mxPow=ceil(log2(n));//mx power of 2 that is less than or equal to len
    vector<vector<int>> dp(n,vector<int>(mxPow+1,0));
    for(int i=0;i<n;i++){
        dp[i][0]=a[i];
    }
    for(int j=1;j<=ceil(log2(n));j++){
        for(int i=0;i+(1<<j)<n;i++){
            dp[i][j]=min(dp[i][j-1],dp[i+(1<<j)][j-1]);
        }
    }
    int q;cin>>q;
    for(int i=0;i<q;i++){
        int l,r;cin>>l>>r;
        l--,r--;
        int len=r-l+1;
        cout<<min(dp[l][log2(len)],dp[r-log2(len)+1][log2(len)]);
    }


    return 0;
}