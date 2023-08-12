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
        int n,k;cin>>n>>k;
        vector<pair<int,int>> v(n);
        vector<int> suf(n);
        for(int i=0;i<n;i++){
            int hi;cin>>hi;
            v[i].first=hi;
        }
        for(int i=0;i<n;i++){
            int pi;cin>>pi;
            v[i].second=pi;
        }
        sort(begin(v),end(v));
        vector<int> h(n),p(n);
        int mn=INT_MAX;
        for(int i=n-1;i>=0;i--){
            h[i]=v[i].first;
            p[i]=v[i].second;
            mn=min(mn,p[i]);
            suf[i]=mn;
        }
        int fl=0;
        auto st=begin(h);
        dbg(h,p,suf);
        int par=k;
        while(k>0){
            dbg(k);
            auto it=upper_bound(st,end(h),par);
            if(it==end(h)){
                fl=1;break;
            }else{
                int idx=it-begin(h);
                st=it;
                dbg(idx);
                if(k<=suf[idx]){
                    dbg(idx);
                    break;
                }
                par=2*par-suf[idx];
                k-=suf[idx];
            }
        }
        if(fl)cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
        
    }

    return 0;
}