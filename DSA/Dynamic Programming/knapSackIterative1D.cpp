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

    int n,W;cin>>n>>W;
    vector<int> val(n),w(n);
    for(auto &x:val)cin>>x;
    for(auto &x:w)cin>>x;
    vector<int> dp(W+1,0);
    for(int i=0;i<n;i++){
        for(int j=W;j>=0;j--){
            if(j-w[i]>=0)dp[j]=max(dp[j],dp[j-w[i]]+val[i]);
        }
    }
    cout<<dp[W]<<'\n';

    return 0;
}