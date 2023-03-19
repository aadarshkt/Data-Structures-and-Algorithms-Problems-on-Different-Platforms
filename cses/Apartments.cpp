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

    int n,m,k;cin>>n>>m>>k;
    vector<int> a(n),b(m);
    for(auto &x:a)cin>>x;
    for(auto &x:b)cin>>x;
    sort(begin(a),end(a));
    sort(begin(b),end(b));
    int ans=0;
    int j=0,l=0;
    while(l<=m-1&&j<=n-1){
        if(b[l]>=a[j]-k&&b[l]<=a[j]+k){
            j++,l++;
            ans++;
        }else if(b[l]<a[j]-k){
            l++;
        }else if(b[l]>a[j]+k){
            j++;
        }
    }
    cout<<ans<<'\n';

    return 0;
}