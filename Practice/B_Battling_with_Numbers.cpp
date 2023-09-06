#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

const int mod=998244353;

int binaryexp(int a,int b){
 int ans=0;
 if(b<0)return 0;
 if(b==0)return 1;
 else if(b==1)return a;
 else if(b%2){
   ans=(a*(binaryexp((a*a)%mod,b/2)%mod))%mod;
 }
 else ans=binaryexp((a*a)%mod,b/2);
 return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<int> a(n),ax(n);
    for(auto &x:a)cin>>x;
    for(auto &x:ax)cin>>x;
    int m;cin>>m;
    vector<int> b(m),bx(m);
    for(auto &x:b)cin>>x;
    for(auto &x:bx)cin>>x;

    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[a[i]]+=ax[i];
    }
    dbg(mp,b,bx);
    int fl=1;
    for(int i=0;i<m;i++){
        if(mp.count(b[i])&&mp[b[i]]>=bx[i]){
            mp[b[i]]-=bx[i];
            if(mp[b[i]]==0)mp.erase(b[i]);
        }else{
            dbg(b[i]);
            fl=0;break;
        }
    }
    if(!fl)cout<<0<<'\n';
    else{
        int sz=mp.size();
        dbg(sz);
        cout<<binaryexp(2,sz)<<'\n';
    }

    return 0;
}