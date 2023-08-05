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

    int n,q;cin>>n>>q;
    vector<int> v(n);
    for(auto &x:v)cin>>x;
    vector<int> dp(n,0),fl(n,0);
    for(int i=0;i<n-2;i++){
        int a=v[i],b=v[i+1],c=v[i+2];
        if(a-b>=0&&b-c>=0){
            fl[i+1]=1;
        }
    }
    dp[0]=fl[0];
    for(int i=1;i<n;i++){
        dp[i]=dp[i-1]+fl[i];
    }
    // for(auto x:dp)cout<<x<<' ';
    cout<<'\n';
    for(int i=0;i<q;i++){
        int l,r;cin>>l>>r;
        l--,r--;
        int ans=r-l+1-dp[r];
        if(l>0)ans+=dp[l-1];
        if(fl[r]==1)ans++;
        if(fl[l]==1&&l!=r)ans++;
        cout<<ans<<'\n';
    }

    return 0;
}