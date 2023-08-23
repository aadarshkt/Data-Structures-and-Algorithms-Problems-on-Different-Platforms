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

    int n;cin>>n;
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    //dp[i][j] --> is j xor value possible or not upto ith index.
    vector<vector<int>> dp(n,vector<int>(1<<10,0));
    dp[0][0]=1,dp[0][a[0]]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<(1<<10);j++){
            if(dp[i-1][j]){
                dp[i][j]=1;
                int nxt=j^a[i];
                dbg(i,j,a[i],nxt);
                dp[i][j^(a[i])]=1;
            }
        }
    }
    dbg(dp);
    int ans=-1;
    int fl=0;
    for(int i=0;i<n;i++){
        if(i>0&&dp[i-1][a[i]])fl=1;
        if(fl)ans=0;
        else ans=-1;
        for(int j=0;j<(1<<10);j++){
            if(dp[i][j]){
                ans+=dp[i][j];
            }
        }
        cout<<ans<<' ';
    }

    return 0;
}