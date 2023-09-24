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
    vector<int> a(n),pre(n);
    for(auto &x:a)cin>>x;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        pre[i]=sum;
    }
    for(int i=0;i<q;i++){
        int l,r;cin>>l>>r;
        l--,r--;
        int ans=pre[r];
        if(l!=0)ans-=pre[l-1];
        cout<<ans<<'\n';
    }

    return 0;
}