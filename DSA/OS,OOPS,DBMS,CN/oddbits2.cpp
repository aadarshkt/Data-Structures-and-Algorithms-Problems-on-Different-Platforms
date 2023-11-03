#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

bool calc(int mid){
    int i=2;
    int ans=0;
    int cnt=0;
    while(i<=2*mid){
        cnt+=1;
        if(cnt%2==0){
            i*=2;
            continue;
        }
        int vl=mid/i;
        ans+=vl*(i/2);
        vl=mid%i;
        vl-=i/2;
        vl+=1;
        if(vl>0)ans+=vl;
        i*=2;
    }
    return ans;
}

int solve(int k){
    int l=1,r=2*k;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(calc(mid)>k)r=mid-1;
        else l=mid+1;
    }
    return l-1;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;cin>>t;
    for(int i=0;i<t;i++){
        int k;cin>>k;
        int out_;
        out_=solve(k);
        cout<<out_;
        cout<<'\n';
    }

    return 0;
}