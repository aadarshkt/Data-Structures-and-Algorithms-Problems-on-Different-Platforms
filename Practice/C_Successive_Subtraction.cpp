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
    sort(begin(a),end(a));
    int l=0,r=n-1;
    int mx=a[r],mn=a[l];
    vector<pair<int,int>> ans;
    while(l<r){
        if(r-l==1){
            ans.push_back({mx,mn});
            break;
        }
        ans.push_back({mn,mx});
        mn=mn-mx;
        r--;
        mx=a[r];
    }
    int sz=ans.size();
    cout<<ans[sz-1].first-ans[sz-1].second<<'\n';
    for(auto x:ans)cout<<x.first<<' '<<x.second<<'\n';

    return 0;
}