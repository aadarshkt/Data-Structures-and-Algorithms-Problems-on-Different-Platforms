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

    int n,k;cin>>n>>k;
    vector<int> a(n),z(n),o(n);
    for(auto &x:a)cin>>x;
    int sum1=0,sum2=0;
    for(int i=0;i<n;i++){
        if(a[i]==1)sum1++;
        else sum2++;
        z[i]=sum2;
        o[i]=sum1;
    }
    int ans=0,l=-1,r=-1;
    for(int i=0;i<n;i++){
        int cnto=o[i];
        dbg(cnto);
        int idx=-1;
        if(z[i]-k<=0)idx=-1;
        else{
            auto it=lower_bound(begin(z),begin(z)+i,z[i]-k);
            if(it!=end(z)){
                idx=it-begin(z);
            }
        }
        if(idx!=-1)cnto-=o[idx];
        dbg(i,idx);
        int cntz=min(k,z[i]);
        dbg(ans,cntz,cnto);
        if(cntz+cnto>ans){
            ans=cntz+cnto;
            r=i,l=idx+1;
            dbg(l,r);
        }
    }
    if(l==-1){
        cout<<o[n-1]<<'\n';
        for(auto x:a)cout<<x<<' ';
        return 0;
    }
    dbg(l,r);
    for(int i=l;i<=r;i++){
        a[i]=1;
    }
    cout<<ans<<'\n';
    for(auto x:a)cout<<x<<' ';
    cout<<'\n';


    return 0;
}
