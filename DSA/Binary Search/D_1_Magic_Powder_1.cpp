#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

bool pred(int mid,vector<int> &a,vector<int> &b,int n,int k){
    //mid number of cookies.
    int need=0;
    for(int i=0;i<n;i++){
        int req=a[i]*mid;
        need+=b[i]-req>=0?0:req-b[i];
    }
    if(need<=k)return true;
    return false;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;cin>>n>>k;
    vector<int> a(n),b(n);
    for(auto &x:a)cin>>x;
    for(auto &x:b)cin>>x;
    int lo=-1,hi=INT_MAX;
    while(hi-lo>1){
        int mid=lo+(hi-lo)/2;
        if(pred(mid,a,b,n,k)){
            lo=mid;
        }else hi=mid;
    }
    cout<<lo<<'\n';

    return 0;
}