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
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    int cnt=0,mx=0;
    for(int i=1;i<n;i++){
        if(a[i-1]>=a[i])cnt++;
        else{
            mx=max(mx,cnt);
            cnt=0;
        }
    }
    mx=max(mx,cnt);
    cout<<mx<<'\n';

    return 0;
}