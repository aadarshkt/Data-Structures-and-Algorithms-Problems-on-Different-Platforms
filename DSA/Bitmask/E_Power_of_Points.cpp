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
        vector<pair<int,int>> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i].first;
            a[i].second=i;
        }
        sort(begin(a),end(a));
        int ans=n;
        for(int i=1;i<n;i++){
            ans+=(a[i].first-a[i-1].first)*(n-i);
        }
        vector<int> res(n);
        for(int i=0;i<n;i++){
            res[a[i].second]=ans;
            if(i<n)ans+=(2*(i+1)-n)*(a[i+1].first-a[i].first);
        }
        for(auto x:res)cout<<x<<' ';
        cout<<'\n';
    }

    return 0;
}