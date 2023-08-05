#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int dp[501][501];
int sol(int n,int m){
    if(n==m)return dp[n][m]=0;
    if(dp[n][m]!=-1)return dp[n][m];
    int ans=INT_MAX;
    for(int i=1;i<=n/2;i++){
        ans=min(ans,1+sol(i,m)+sol(n-i,m));
    }
    for(int i=1;i<=m/2;i++){
        ans=min(ans,1+sol(n,i)+sol(n,m-i));
    }
    return dp[n][m]=ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp,-1,sizeof(dp));
    int n,m;cin>>n>>m;
    cout<<sol(n,m)<<'\n';

    return 0;
}