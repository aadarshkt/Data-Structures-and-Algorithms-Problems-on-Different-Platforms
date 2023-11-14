#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

bool pred(int x,int n,int m){
    if((x*(x+1)/2)>=(n-m-1-x))return true;
    return false;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;cin>>n>>m;
    if(m>=n)cout<<n<<'\n';
    else{
        int ans=m+1;
        int lo=-1,hi=2e9+1;
        while(hi-lo>1){
            int mid=lo+(hi-lo)/2;
            if(pred(mid,n,m)){
                hi=mid;
            }else lo=mid;
        }
        cout<<ans+hi<<'\n';
    }

    return 0;
}