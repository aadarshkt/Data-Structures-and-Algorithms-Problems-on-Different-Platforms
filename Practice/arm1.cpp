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

    int r,c,n,w;cin>>r>>c>>n>>w;
    vector<vector<int>> v(r,vector<int>(c,0)),dp(r,vector<int>(c,0));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>v[i][j];
        }
    }
    int sum=0;
    for(int i=0;i<r;i++){
        sum+=v[i][0];
        dp[i][0]=sum;
    }
    sum=0;
    for(int j=0;j<c;j++){
        sum+=v[0][j];
        dp[0][j]=sum;
    }
    for(int i=1;i<r;i++){
        for(int j=1;j<c;j++){
            dp[i][j]=v[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
    }
    dbg(dp);
    int cnt=0;
    for(int i=n-1;i<r;i++){
        for(int j=n-1;j<c;j++){
            int subsum = dp[i][j];
            if(i-n>=0)subsum-=dp[i-n][j];
            if(j-n>=0)subsum-=dp[i][j-n];
            if(i-n>=0&&j-n>=0)subsum+=dp[i-n][j-n];
            if(subsum>=w)cnt++;
        }
    }
    cout<<cnt<<'\n';

    return 0;
}