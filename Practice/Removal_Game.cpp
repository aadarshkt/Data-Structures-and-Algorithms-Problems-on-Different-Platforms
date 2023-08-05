#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

//sol(l,r) --> maximum difference that a player can achieve score in the interval l,r;
int dp[5000+1][5000+1];
int sol(vector<int> &a,int l,int r,int n){
    if(l>r)return dp[l][r]=0;
    if(dp[l][r]!=-1)return dp[l][r];
    int left=a[l]-sol(a,l+1,r,n),right=a[r]-sol(a,l,r-1,n);
    dbg(left,right);
    return dp[l][r]=max(left,right);
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp,-1,sizeof(dp));
    int n;cin>>n;
    vector<int> a(n);
    int sum=0;
    for(auto &x:a){
        cin>>x;
        sum+=x;
    }
    int ans=sol(a,0,n-1,n);
    cout<<(sum+ans)/2<<'\n';

    return 0;
}