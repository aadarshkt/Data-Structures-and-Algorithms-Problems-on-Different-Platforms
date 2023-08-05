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
    vector<int> b(n),diff(n);
    for(auto &x:b)cin>>x;
    for(int i=0;i<n;i++){
        diff[i]=i+1-b[i];
    }
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[diff[i]]+=b[i];
    }
    int ans=0;
    for(auto x:mp){
        ans=max(ans,x.second);
    }
    cout<<ans<<'\n';

    return 0;
}