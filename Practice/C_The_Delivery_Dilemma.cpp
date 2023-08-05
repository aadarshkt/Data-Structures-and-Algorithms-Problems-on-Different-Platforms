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
        int n;cin>>n;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            int ti;cin>>ti;
            v.push_back({ti,-1});
        }
        for(int i=0;i<n;i++){
            int ti;cin>>ti;
            v[i].second=ti;
        }
        sort(begin(v),end(v));
        int sum=0;
        map<int,int> mp;
        vector<int> dt(n),suf(n);
        for(int i=n-1;i>=0;i--){
            dt[i]=v[i].first;
            if(!mp.count(dt[i]))mp[dt[i]]=i;
            sum+=v[i].second;
            suf[i]=sum;
        }
        int ans=max(sum,v[n-1].first);
        dbg(mp,suf);
        for(auto x:mp){
            int idx=x.second;
            if(idx+1<n){
                ans=min(ans,max(x.first,suf[idx+1]));
                dbg(ans);
            }else{
                ans=min(ans,x.first);
            }
        }
        ans=min(ans,sum);
        cout<<ans<<'\n';
    }

    return 0;
}