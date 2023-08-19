#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int dp[1<<20];
int solve(vector<int> &a,int n,int prev_gc,int mask){
    if(mask==(1<<n)-1)return 0;
    if(dp[mask]!=-1)return dp[mask];
    int ans=0;
    for(int j=0;j<n;j++){
        if(mask&(1<<j))continue;
        int curr_gc=__gcd(a[j],prev_gc);
        ans=max(ans,curr_gc+solve(a,n,curr_gc,mask^(1<<j)));
    }
    return dp[mask]=ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp,-1,sizeof(dp));
    int n;cin>>n;
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    cout<<solve(a,n,0,0)<<'\n';

    return 0;
}