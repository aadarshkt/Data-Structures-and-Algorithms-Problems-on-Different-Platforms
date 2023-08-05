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
    vector<int> h(n),pre(n);
    for(auto &x:h)cin>>x;
    sort(begin(h),end(h));
    map<int,int> mp;
    for(int i=0;i<n;i++){
        if(!mp.count(h[i]))mp[h[i]]=i;
    }
    int sum=0,mx=0,mn=1e10;
    for(int i=0;i<n;i++){
        sum+=h[i];
        pre[i]=sum;
        mx=max(mx,h[i]);
        mn=min(mn,h[i]);
    }
    //prev stores total blocks remove till now.
    //next stores prev blocks that were less than k.
    int ans=0,next=0,prev=0;
    for(int i=mx-1;i>=mn;i--){
        auto it=mp.upper_bound(i);
        int idx=it->second;
        int nos=pre[n-1];
        if(idx-1>=0)nos-=pre[idx-1];
        nos-=i*(n-idx);
        nos+=next;
        nos-=prev;
        if(nos==k){
            ans++;
            prev+=nos;
            next=0;
        }
        else if(nos<k){
            next=nos;
        }else if(nos>k){
            nos-=next;
            ans++;
            prev+=next;
            next=nos;
        }
        
    }
    if(next>0)ans++;
    cout<<ans<<'\n';

    return 0;
}