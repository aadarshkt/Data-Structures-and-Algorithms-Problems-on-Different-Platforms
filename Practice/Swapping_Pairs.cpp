#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

int dp[1001][10000+1];
int solve(vector<pair<int,int>> &v,int n,int sum,int i,int m){
    if(sum==m)return 1;
    else if(sum>m)return 0;
    if(i==n)return 0;
    if(dp[i][sum]!=-1)return dp[i][sum];
    int ans=0;
    ans=solve(v,n,sum+v[i].first,i+1,m)|solve(v,n,sum+v[i].second,i+1,m);
    return dp[i][sum]=ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        int n,m;cin>>n>>m;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            int a,b;cin>>a>>b;
            v.push_back({a,b});
        }
        int ans=solve(v,n,0,0,m);
        if(ans)cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }

    return 0;
}