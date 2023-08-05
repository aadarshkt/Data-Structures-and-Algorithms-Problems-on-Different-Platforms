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

    int n,t;cin>>n>>t;
    vector<int> v(n);
    for(auto &x:v)cin>>x;
    sort(begin(v),end(v));
    int lo=0,hi=1e18+1,ans=hi;
    while(hi-lo>1){
        int mid=lo+(hi-lo)/2;
        int pr=0;
        for(int i=0;i<n;i++){
            pr+=mid/v[i];
            if(pr>=t)break;
        }
        if(pr>=t){
            ans=min(ans,mid);
            hi=mid;
        }else{
            lo=mid;
        }
    }
    cout<<ans<<'\n';

    return 0;
}