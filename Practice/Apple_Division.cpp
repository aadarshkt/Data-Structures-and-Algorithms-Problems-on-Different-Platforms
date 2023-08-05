#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

void subset(int sum,vector<int> &a,int i,int n,int total,int &ans){
    if(i==n)return;
    ans=min(ans,abs(2*sum-total));
    subset(sum+a[i],a,i+1,n,total,ans);
    subset(sum,a,i+1,n,total,ans);
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<int> a(n);
    int sum=0;
    for(auto &x:a){
        cin>>x;
        sum+=x;
    }
    int ans=INT_MAX;
    subset(0,a,0,n,sum,ans);
    cout<<ans<<'\n';

    return 0;
}