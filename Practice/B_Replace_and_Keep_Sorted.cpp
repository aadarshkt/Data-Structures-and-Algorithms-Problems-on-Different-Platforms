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

    int n,q,k;cin>>n>>q>>k;
    vector<int> a(n),fr(n,0),ba(n,0),pre(n,0);
    for(auto &x:a)cin>>x;
    for(int i=0;i<n-1;i++){
        fr[i]=a[i+1]-a[i]-1;
    }
    fr[n-1]=k-a[n-1];
    ba[0]=a[0]-1;
    for(int i=1;i<n;i++){
        ba[i]=fr[i-1];
    }
    for(int i=0;i<n;i++){
        pre[i]=fr[i]+ba[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=pre[i];
        pre[i]=sum;
    }
    dbg(pre);
    for(int i=0;i<q;i++){
        int l,r;cin>>l>>r;
        l--,r--;
        int ans=0;
        ans+=pre[r];
        if(l>0)ans-=pre[l-1];
        if(r!=n-1){
            ans-=fr[r];
            ans+=k-a[r];
        }
        if(l!=0){
            ans-=ba[l];
            ans+=a[l]-1;
        }
        cout<<ans<<'\n';
    }

    return 0;
}