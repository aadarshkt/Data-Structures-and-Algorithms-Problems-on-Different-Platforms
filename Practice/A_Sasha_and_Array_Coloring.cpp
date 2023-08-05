#include <bits/stdc++.h>
using namespace std;

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
        vector<int> v(n);
        for(auto &x:v)cin>>x;
        sort(begin(v),end(v));
        int ans=0;
        dbg(v);
        for(int i=0;i<n;i++){
            if(n-i-1<=i)break;
            ans+=v[n-i-1]-v[i];
        }
        cout<<ans<<'\n';
    }

    return 0;
}