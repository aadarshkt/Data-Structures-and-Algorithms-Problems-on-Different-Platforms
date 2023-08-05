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
    vector<tuple<int,int,int>> v;
    map<int,int> dp;
    for(int i=0;i<n;i++){
        int a,b,p;cin>>a>>b>>p;
        v.push_back({b,a,p});
    }
    sort(begin(v),end(v));
    dp[0]=0;//best answer upto ending project day i;
    int ans=0;//best answer so far.
    for(auto &x:v){
        int b,a,p;
        tie(b,a,p)=x;
        auto it=dp.lower_bound(a);
        it--;
        ans=max(ans,p+it->second);
        dp[b]=ans;
    }
    cout<<ans<<'\n';

    return 0;
}