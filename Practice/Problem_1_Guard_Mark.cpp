#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

void setIO(string name = "")
{
    cin.tie(0)->sync_with_stdio(0);
    if (name.length())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    setIO("guard");
    int n,H;cin>>n>>H;
    vector<int> h(n),w(n),s(n);
    for(int i=0;i<n;i++){
        int hi,wi,si;cin>>hi>>wi>>si;
        h[i]=hi,w[i]=wi,s[i]=si;
    }
    vector<pair<int,int>> dp((1<<n),{0,INT_MIN});
    dp[0].second=INT_MAX;
    for(int mask=1;mask<(1<<n);mask++){
        for(int i=0;i<n;i++){
            if(!(mask&(1<<i)))continue;
            dp[mask].second=max(dp[mask].second,min(dp[mask^(1<<i)].second-w[i],s[i]));
            dp[mask].first=dp[mask^(1<<i)].first+h[i];
        }
    }
    int max_safety=-1;
    for(int mask=1;mask<(1<<n);mask++){
        if(dp[mask].first>=H)max_safety=max(max_safety,dp[mask].second);
    }
    dbg(dp);
    if(max_safety<0)cout<<"Mark is too tall"<<'\n';
    else cout<<max_safety<<'\n';


    return 0;
}