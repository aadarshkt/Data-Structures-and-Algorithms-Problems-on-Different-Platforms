#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

const int mod=1e9+7;

void fillDP(vector<vector<char>> &v,vector<vector<int>> &dp,int i,int j){
    if(i>0){
        if(i>1){
            if(v[i-2][j]=='*')(dp[i][j]+=dp[i-1][j])%=mod;
            else (dp[i][j]+=2*dp[i-1][j])%=mod;
        }
        else (dp[i][j]+=dp[i-1][j])%=mod;
    }
    if(j>0){
        if(j>1){
            if(v[i][j-2]=='*')(dp[i][j]+=dp[i][j-1])%=mod;
            else (dp[i][j]+=2*dp[i][j-1])%=mod;
        }else (dp[i][j]+=dp[i][j-1])%=mod;
    }
}

void solve(vector<vector<char>> &v,vector<vector<int>> &dp,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='*')continue;
            fillDP(v,dp,i,j);
        }
    }
}



int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n,m;cin>>n>>m;
        vector<vector<char>> v(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>v[i][j];
            }
        }
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0]=1;
        solve(v,dp,n,m);
        dbg(dp);
        cout<<dp[n-1][m-1]<<'\n';
    }

    return 0;
}