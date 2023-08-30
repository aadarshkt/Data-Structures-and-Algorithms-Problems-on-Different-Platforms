#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

bool fun(int mid,int n){
    if((mid*(mid-1)/2)<=n)return 1;
    return 0;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;cin>>n;
        int lo=0,hi=min<int>(2e9, 2 * n);
        int ans=0;
        while(hi-lo>1){ 
            int mid=lo+(hi-lo)/2;
            if(fun(mid,n)){
                ans=max(ans,mid);
                lo=mid;
            }else hi=mid;
        }
        if((ans*(ans-1)/2)==n)cout<<ans<<'\n';
        else{
            cout<<n-(ans*(ans-1)/2)+ans<<'\n';
        }
    }

    return 0;
}