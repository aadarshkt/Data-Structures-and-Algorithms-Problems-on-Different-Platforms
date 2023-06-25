#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int minCost(vector<vector<int>> &mat,int n,vector<vector<int>> &dp,int i,int mask){
    if(i==n)return 0;
    if(dp[i][mask]!=-1)return dp[i][mask];
    int ans=INT_MAX;
    for(int j=0;j<n;j++){
        if(mask&(1<<j))
            ans=min(ans,mat[j][i]+minCost(mat,n,dp,i+1,mask^(1<<j)));
    }
    return dp[i][mask]=ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<vector<int>> mat(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<minCost(mat,n,dp,0,(1<<n)-1)<<'\n';

    return 0;
}