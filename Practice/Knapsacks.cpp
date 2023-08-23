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

    int n,c;cin>>n>>c;
    vector<int> v(n),w(n);
    int sum=0;
    for(auto &x:v){
        cin>>x;
        sum+=x;
    }
    dbg(sum);
    for(auto &x:w)cin>>x;
    vector<int> dp(sum+1,INT_MAX);
    //dp[i] --> minimum knapsack capacity needed to make value i
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int j=sum;j>=v[i];j--){
            dp[j]=min(dp[j],w[i]+dp[j-v[i]]);
        }
    }
    dbg(dp);
    int ans=0;
    for(int i=0;i<=sum;i++){
        if(dp[i]<=c)ans=i;
    }
    cout<<ans<<'\n';
    return 0;
}