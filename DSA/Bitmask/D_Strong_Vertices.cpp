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
        vector<int> a(n),b(n);
        for(auto &x:a)cin>>x;
        for(auto &x:b)cin>>x;
        vector<int> diff(n);
        int mx=LLONG_MIN;
        for(int i=0;i<n;i++){
            diff[i]=a[i]-b[i];
            mx=max(mx,diff[i]);
        }
        vector<pair<int,int>> ver;
        for(int i=0;i<n;i++){
            ver.push_back({diff[i],i});
        }
        sort(begin(ver),end(ver));
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(ver[i].first==mx)ans.push_back(ver[i].second+1);
        }
        sort(begin(ans),end(ans));
        cout<<(int)ans.size()<<'\n';
        for(auto x:ans)cout<<x<<' ';
        cout<<'\n';

    }

    return 0;
}