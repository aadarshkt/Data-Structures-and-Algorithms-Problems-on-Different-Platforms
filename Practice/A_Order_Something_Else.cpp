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

    int n,p,q;cin>>n>>p>>q;
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    int ans=p;
    for(int i=0;i<n;i++){
        ans=min(ans,q+a[i]);
    }
    cout<<ans<<'\n';

    return 0;
}