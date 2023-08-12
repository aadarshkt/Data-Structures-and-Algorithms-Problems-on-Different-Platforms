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

    int n,p,k;cin>>n>>p>>k;
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    vector<vector<int>> s(n,vector<int>(p));
    for(int i=0;i<n;i++)
        for(int j=0;j<p;j++)
            cin>>s[i][j];
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)v.push_back({a[i],i});
    sort(rbegin(v),rend(v));
    dbg(v);
    vector<int> ind(n);
    for(int i=0;i<n;i++)ind[i]=v[i].second;
    vector<vector<int>> dp(n,vector<int>(1<<p,-1));
    dp[0][0]=0;
    for(int i=0;i<n;i++){
        int x=ind[i];
        for(int mask=0;mask<(1<<p);mask++){
            int taken=__builtin_popcount(mask);//filled positions
            if(i-taken<k){
                for(int j=0;j<p;j++){
                    if(i==0){
                        dp[i][mask]=max({dp[i][mask],a[x]});
                    }else dp[i][mask]=max({dp[i][mask],dp[i-1][mask]+a[x]});
                    if(mask&(1<<j))continue;
                    if(i>0)dp[i][mask]=max(dp[i][mask],dp[i-1][mask^(1<<j)]+s[x][j]);
                }
            }
            for(int j=0;j<p;j++){
                if(mask&(1<<j))continue;
                if(i==0){
                    dp[i][mask]=max(dp[i][mask],s[x][j]);
                }else dp[i][mask]=max({dp[i][mask],dp[i-1][mask^(1<<j)]+s[x][j]});
            }
            if(i>0)dp[i][mask]=max(dp[i][mask],dp[i-1][mask]);
        }
    }
    dbg(dp);
    cout<<dp[n-1][(1<<p)-1]<<'\n';

    return 0;
}