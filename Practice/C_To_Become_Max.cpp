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
        int ans=0;
        for(int idx=0;idx<n;idx++){
            int lo=a[idx]-1,hi=1e10;
            ans=max(ans,a[idx]);
            while(hi-lo>1){
                int mid=lo+(hi-lo)/2;
                int req=0;
                int val=mid;
                if(mid<=a[idx])break;
                int fl=0;
                for(int i=idx;i<n-1;i++){
                    req+=(val)-a[i];
                    val--;
                    if(val<=a[i+1]){
                        fl=1;
                        break;
                    }
                }
                if(hi<15){
                    dbg(t,mid,lo,hi,req);
                    dbg(fl);
                }
                if(fl){
                    if(req>k)hi=mid;
                    else{
                        lo=mid;
                        ans=max(ans,mid);
                    }
                }else hi=mid;
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}