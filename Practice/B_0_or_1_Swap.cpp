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
    int cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]!=i+1)cnt++;
    }
    if(cnt==2||cnt==0)cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';

    return 0;
}