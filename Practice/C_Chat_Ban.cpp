#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int calc(int k,int x){
    int res=0;
    if(x<=k)res=x*(x+1)/2;
    else{
        res+=k*(k+1)/2;
        res+=(k-1)*(k)/2;
        res-=(2*k-1-x)*(2*k-x)/2;
    }
    return res;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int k,x;cin>>k>>x;
        int lo=0,hi=2*k;
        while(hi-lo>1){
            int mid=lo+(hi-lo)/2;
            int cnt=calc(k,mid);
            if(cnt>=x)hi=mid;
            else lo=mid;
        }
        if(hi==2*k)cout<<2*k-1<<'\n';
        else cout<<hi<<'\n';
    }

    return 0;
}