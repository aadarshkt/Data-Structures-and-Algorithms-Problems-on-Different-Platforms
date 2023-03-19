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
    vector<int> v(n);
    for(auto &x:v)cin>>x;
    int sum=0,ans=INT_MIN;
    for(int i=0;i<n;i++){
        sum+=v[i];
        ans=max(ans,sum);
        if(sum<0)sum=0;
    }
    cout<<ans<<'\n';

    return 0;
}