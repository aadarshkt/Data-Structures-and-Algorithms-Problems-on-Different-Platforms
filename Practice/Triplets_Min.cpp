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
        int n,q;cin>>n>>q;
        vector<int> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        sort(begin(a),end(a));
        int prv=0;
        map<int,int> mp;
        for(int i=n;i>=3;i--){
            int cur=((i-1)*(i-2))/2;
            mp[prv+cur]=a[(n-i)];
            prv+=cur;
        }
        dbg(mp);
        for(int i=0;i<q;i++){
            int k;cin>>k;
            auto it=mp.lower_bound(k);
            cout<<it->second<<'\n';
        }
    }

    return 0;
}