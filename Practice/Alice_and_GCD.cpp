#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int dp[1<<22];
int solve(vector<int> &a,int k,int n,int mask){
    if(mask==(1<<n)-1)return 0;
    if(dp[mask]!=-1)return dp[mask];
    int ans=0;
    for(int i=0;i<n;i++){
        if(mask&(1<<i))continue;
        for(int j=i+1;j<n;j++){
            if(mask&(1<<j))continue;
            ans=max(ans,(k+1)*__gcd(a[i],a[j])+solve(a,k+1,n,mask|(1<<i)|(1<<j)));
        }
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
    cout<<solve(a,0,n,0)<<'\n';

    return 0;
}