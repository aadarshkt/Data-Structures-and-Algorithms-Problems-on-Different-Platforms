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
    vector<int> b(n-1),a(n);
    for(auto &x:b)cin>>x;
    a[0]=b[0],a[n-1]=b[n-2];
    for(int i=1;i<n-1;i++){
        a[i]=min(b[i],b[i-1]);
    }
    int sum=0;
    for(auto x:a)sum+=x;
    cout<<sum;

    return 0;
}