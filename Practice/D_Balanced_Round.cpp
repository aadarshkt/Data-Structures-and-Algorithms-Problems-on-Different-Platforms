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
        int n,k;cin>>n>>k;
        vector<int> a(n);
        for(auto &x:a)cin>>x;
        sort(begin(a),end(a));
        int mx=1,cnt=1;
        for(int i=1;i<n;i++){
            if(abs(a[i]-a[i-1])<=k){
                cnt++;
            }else cnt=1;
            mx=max(mx,cnt);
        }
        cout<<n-mx<<'\n';
    }

    return 0;
}