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
        int a,b,n;cin>>a>>b>>n;
        vector<int> arr(n);
        for(auto &x:arr)cin>>x;
        int ans=b-1;
        int val=1;
        for(int i=0;i<n;i++){
            val=min(val+arr[i],a);
            ans+=val-1;
            val=1;
        }
        ans++;
        cout<<ans<<'\n';

    }

    return 0;
}