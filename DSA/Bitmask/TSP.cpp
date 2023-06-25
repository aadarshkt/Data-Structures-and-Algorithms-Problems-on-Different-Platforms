#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

//calculate minimum cost for each last destination.
int minCost(vector<vector<int>> &mat,vector<vector<int>> &dp,int mask,int i,int n,int vis){
    if(vis==n){
        return 0;
    }
    int ans=INT_MAX;
    for(int j=1;j<n;j++){
        if(mask&(1<<j)){
            ans=min(ans,minCost(mat,dp,mask^(1<<j),j,n,vis+1)+mat[i][j]);
        }
    }
    return dp[vis][mask]=ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}