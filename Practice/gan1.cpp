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
    vector<int> arr(n),dp(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    dp[0] = arr[0];
    dp[1] = arr[1];

    //dp[i] -> maximum sum upto index i such that no elements are adjacent.

    for(int i=2;i<n;i++){
        dp[i] = max(dp[i-2] + arr[i], dp[i-1]);
    }
    cout<<max(dp[n-1], dp[n-2])<<'\n'; 

    return 0;
}