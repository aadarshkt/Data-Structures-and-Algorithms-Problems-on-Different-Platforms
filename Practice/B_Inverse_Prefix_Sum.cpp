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
    vector<int> s(n);
    for(auto &x:s)cin>>x;
    vector<int> ans(n);
    int sum=0;
    for(int i=0;i<n;i++){
        ans[i]=s[i]-sum;
        sum=s[i];
    }
    for(auto x:ans)cout<<x<<' ';

    return 0;
}