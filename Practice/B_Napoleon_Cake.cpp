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
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        for(int &x:a)cin>>x;
        vector<int> dp(n,0);
        for(int i=0;i<n;i++){
            dp[i]+=1;
            if(i-a[i]>=0)dp[i-a[i]]-=1;
        }
        int sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=dp[i];
            dp[i]=sum;
        }
        for(int x:dp){
            if(x>=1)cout<<1<<' ';
            else cout<<0<<' ';
        }
        cout<<'\n';
    }

    return 0;
}