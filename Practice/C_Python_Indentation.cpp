
#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif
 
#define int long long
 
const int mod=1e9+7;
 
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;cin>>n;
    vector<char> c(n);
    for(auto &x:c)cin>>x;
    vector<vector<int>> dp(n,vector<int>(n+1,0));
    dp[0][0]=1;
    for(int i=1;i<n;i++){
        int sum=0;
        for(int j=n;j>=0;j--){
            (sum+=dp[i-1][j])%=mod;
            if(c[i-1]=='f'){
                if(j-1>=0)(dp[i][j]+=dp[i-1][j-1])%=mod;
            }else{
                (dp[i][j]=sum)%=mod;
            }
        }
    }
    int ans=0;
    for(int i=0;i<=n;i++){
        (ans+=dp[n-1][i])%=mod;
    }
    cout<<ans<<'\n';
    
 
    return 0;
}