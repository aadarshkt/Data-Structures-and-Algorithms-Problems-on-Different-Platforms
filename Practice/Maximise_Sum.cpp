#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int dp[(int)1e3+1][(int)1e3+1];
int solve(vector<int> &a,int i,int j,int n){
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=INT_MIN;
    if(j-i>=1){
        ans=max({a[i]+solve(a,i+1,j,n),
        a[j]+solve(a,i,j-1,n),a[i]*a[i+1]+solve(a,i+2,j,n),a[j]*a[j-1]+solve(a,i,j-2,n)});
    }else{
        ans=a[i]+solve(a,i+1,j,n);
    }
    return dp[i][j]=ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp,-1,sizeof(dp));
    int n;cin>>n;
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    cout<<solve(a,0,n-1,n)<<'\n';

    return 0;
}