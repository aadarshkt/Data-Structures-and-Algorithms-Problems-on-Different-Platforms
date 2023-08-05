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

    int n,k,v;cin>>n>>k>>v;
    vector<int> a(n);
    int sum=0;
    for(auto &x:a){
        cin>>x;
        sum+=x;
    }
    vector<int> dp(sum+1,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<sum+1;j++){
            if(dp[j])dp[j+a[i]]=1;
        }
        dp[a[i]]=1;
    }
    for(int i=0;i<sum+1;i++){
        if(dp[i])cout<<i<<' ';
    }

    return 0;
}