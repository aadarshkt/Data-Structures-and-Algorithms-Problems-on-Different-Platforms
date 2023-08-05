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
        int l,r;cin>>l>>r;
        int mx=0;
        for(int i=0;i<=32;i++){
            if(l*pow(2,i)<=r)mx=i;
            else break;
        }
        int hi=l,lo=-1;
        while(hi-lo>1){
            int mid=lo+(hi-lo)/2;
            int val=l*pow(2,mx)+mid*pow(2,mx);
            if(val<=r)lo=mid;
            else hi=mid;
        }
        long double d=l*pow(2,mx)*double(1.5);
        if(d<=r){
            cout<<mx<<' '2*n+
        }
    }

    return 0;
}