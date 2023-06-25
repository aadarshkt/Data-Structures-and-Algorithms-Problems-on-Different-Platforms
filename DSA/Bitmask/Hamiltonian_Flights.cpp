#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int ways(vector<vector<int>> &arr,vector<vector<int>> &dp,int i,int mask,int n){
    if(mask==(1<<(n-1))+1)return 1;
    if(dp[i][mask]!=-1)return dp[i][mask];
    int ans=0;
    for(int j=1;j<n-1;j++){
        if(arr[i][j]){
            if(mask&(1<<j))
                ans+=ways(arr,dp,j,mask^(1<<j),n);
        }
    }
    return dp[i][mask]=ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;cin>>n>>m;
    dbg(n,m);
    int mask=(1<<n)-1;
    dbg(mask);
    vector<vector<int>> arr(n,vector<int>(n,0)),dp(n,vector<int>(mask+1,-1));
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        arr[u-1][v-1]=1;
    }
    cout<<ways(arr,dp,0,mask,n)<<'\n';

    return 0;
}