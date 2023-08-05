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
    vector<int> a(n),b(n);
    for(auto &x:a)cin>>x;
    for(auto &x:b)cin>>x;
    vector<int> diff;
    for(int i=0;i<n;i++){
        diff.push_back(a[i]-b[i]);
    }
    sort(begin(diff),end(diff));
    int sz=diff.size();
    dbg(diff);
    int ans=0;
    for(int i=0;i<n;i++){
        int pos=a[i]-b[i];
        auto it=lower_bound(begin(diff),end(diff),-pos+1);
        dbg(ans);
        if(it!=end(diff)){ans+=sz-(it-begin(diff));}
        if(pos>0)ans--;
        dbg(i,pos,ans);
    }
    cout<<ans/2<<'\n';
    return 0;
}