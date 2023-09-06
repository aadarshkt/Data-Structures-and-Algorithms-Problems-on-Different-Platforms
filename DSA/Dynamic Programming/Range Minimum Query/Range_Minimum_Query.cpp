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

    vector<vector<int>> dp(n,vector<int>(ceil(log2(n)+1),0));
    for(int i=0;i<n;i++){
        dp[i][0]=a[i];
    }
    for(int j=1;j<=ceil(log2(n));j++){
        for(int i=0;i+(1<<j)-1<n;i++){
            dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
        }
    }
    dbg(dp);
    int q;cin>>q;
    for(int i=0;i<q;i++){
        int l,r;cin>>l>>r;
        int len=r-l+1;
        dbg(log2(len));
        int k=log2(len);//the power of 2 which is just less than length;
        cout<<min(dp[l][k],dp[r-(1<<k)+1][log2(len)])<<'\n';
    }


    return 0;
}