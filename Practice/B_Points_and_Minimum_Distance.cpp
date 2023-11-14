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
        n=2*n;
        vector<int> a(n);
        for(auto &x:a)cin>>x;
        sort(begin(a),end(a));
        dbg(a);
        int ans=0;
        vector<int> xx,yy;
        for(int i=0;i<n/2;i++){
            xx.push_back(a[i]);
            if(i==(n/2)-1)continue;
            ans+=abs(a[i]-a[i+1]);
        }
        for(int i=n/2;i<n;i++){
            yy.push_back(a[i]);
            if(i==n-1)continue;
            ans+=abs(a[i]-a[i+1]);
        }
        cout<<ans<<'\n';
        for(int i=0;i<n/2;i++){
            cout<<xx[i]<<' '<<yy[i]<<'\n';
        }
    }

    return 0;
}