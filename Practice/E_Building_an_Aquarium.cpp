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
        int n,x;cin>>n>>x;
        vector<int> a(n);
        for(auto &ele:a)cin>>ele;
        int lo=-1,hi=INT_MAX;
        int ans=0;
        while(hi-lo>1){
            int mid=lo+(hi-lo)/2;
            int cnt=0;
            for(int i=0;i<n;i++){
                if(a[i]<mid)cnt+=mid-a[i];
            }
            if(cnt<=x){
                ans=max(ans,mid);
                lo=mid;
            }else hi=mid;
        }
        cout<<ans<<'\n';
    }

    return 0;
}