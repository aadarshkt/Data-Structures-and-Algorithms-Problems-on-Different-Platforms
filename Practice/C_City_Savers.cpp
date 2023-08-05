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
    vector<int> a(n+1),b(n);
    for(auto &x:a)cin>>x;
    for(auto &x:b)cin>>x;
    int ans=0,prev=0;
    for(int i=0;i<n+1;i++){
        int h=prev;
        if(i<n)h+=b[i];
        int win=min(a[i],h);
        ans+=win;
        if(h-a[i]>=0)prev=h-a[i];
        else prev=0;
    }
    cout<<ans<<'\n';

    return 0;
}