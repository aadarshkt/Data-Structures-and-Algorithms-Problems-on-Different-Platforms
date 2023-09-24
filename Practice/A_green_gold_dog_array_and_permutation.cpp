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

    int t;
    cin >> t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        for(auto &x:a)cin>>x;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({a[i],i});
        }
        sort(rbegin(v),rend(v));
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[v[i].second]=i+1;
        }
        for(auto x:ans)cout<<x<<' ';
        cout<<'\n';
    }

    return 0;
}