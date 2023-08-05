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

    int t;
    cin >> t;
    vector<vector<int>> v(2023+1,vector<int>(2024,0)),dp(2024,vector<int>(2024,0));
    int sx=0,n=2024,val=1;
    map<int,pair<int,int>> mp;
    while(sx!=2024){
        int i=sx,j=0;
        while(i<n&&j<n&&i>=0&&j>=0){
            v[i][j]=val*val;
            mp[val]={i,j};
            i--,j++,val++;
        }
        sx++;
    }
    dp[0][0]=1;
    for(int i=1;i<n;i++){
        dp[i][0]=dp[i-1][0]+v[i][0];
    }
    for(int i=1;i<n;i++){
        dp[0][i]=dp[0][i-1]+v[0][i];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1]+v[i][j]-dp[i-1][j-1];
        }
    }
    while(t--){
        int ni;cin>>ni;
        int i=mp[ni].first,j=mp[ni].second;
        cout<<dp[i][j]<<'\n';
    }

    return 0;
}