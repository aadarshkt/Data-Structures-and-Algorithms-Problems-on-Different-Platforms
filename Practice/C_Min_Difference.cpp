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

    int n,m;cin>>n>>m;
    vector<int> a(n),b(m);
    for(auto &x:a)cin>>x;
    for(auto &x:b)cin>>x;
    sort(begin(b),end(b));
    int mdif=INT_MAX;
    for(int i=0;i<n;i++){
        auto it=lower_bound(begin(b),end(b),a[i]);
        if(it==end(b)){
            mdif=min(mdif,abs(a[i]-b[m-1]));
        }else{
            int val=*it;
            mdif=min(mdif,val-a[i]);
            if(it!=begin(b))it--;
            mdif=min(mdif,abs(*it-a[i]));
        }
    }
    cout<<mdif<<'\n';

    return 0;
}