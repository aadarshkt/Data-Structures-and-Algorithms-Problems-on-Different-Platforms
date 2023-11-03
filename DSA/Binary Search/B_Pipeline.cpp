#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

bool pred(int x,int k,int n){
    if(n>=2&&n<=k)return true;
    if(n>k+(k-2)*(k-1)/2)return false;
    int sum=(k-2)*(k-1)/2;//total sum
    int sum1=(k-1-x)*(k-x-2)/2;
    if(sum-sum1+k>=n)return true;
    return false;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;cin>>n>>k;
    int lo=-1,hi=k+1;
    if(n==1){
        cout<<0<<'\n';
        return 0;
    }
    while(hi-lo>1){
        int mid=lo+(hi-lo)/2;
        if(pred(mid,k,n)){
            hi=mid;
        }else lo=mid;
    }
    if(hi==k+1)cout<<-1<<'\n';
    else cout<<hi+1<<'\n';

    return 0;
}