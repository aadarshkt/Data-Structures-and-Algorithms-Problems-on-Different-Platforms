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
        vector<vector<int>> v(n);
        for(int i=0;i<n;i++){
            int m;cin>>m;
            for(int j=0;j<m;j++){
                int ai;cin>>ai;
                v[i].push_back(ai);
            }
        }
        int ans=0,mn=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<(int)v[i].size();j++){
                sort(begin(v[i]),end(v[i]));
            }
            ans+=v[i][0];
            mn=min(mn,v[i][0]);
        }
        vector<int> b(n);
        int sum=0;
        for(int i=0;i<n;i++){
            b[i]=v[i][1]-v[i][0];
            sum+=b[i];
        }
        dbg(ans,sum);
        int res=ans;
        for(int i=0;i<n;i++){
            res=max(res,ans-v[i][0]+mn+sum-b[i]);
        }
        cout<<res<<'\n';


        // int mostMin=INT_MAX,mst2=INT_MAX;
        // dbg(v);
        // int ans=0;
        // map<int,int> mp;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<(int)v[i].size();j++){
        //         pair<int,int> res=fun(v[i]);
        //         int mn=res.first,mn2=res.second;
        //         mp[mn]+=mn2-mn;
        //     }
        //     ans+=*(v[i].begin());
        // }
        // dbg(mp);
        // auto it=mp.begin();
        // mostMin=it->first;
        // it++;
        // mst2=it->first;
        // mp[mostMin]-=abs(mst2-mostMin);
        // int mx=0;
        // dbg(mp);
        // for(auto x:mp){
        //     mx=max(mx,x.second);
        // }
        // dbg(ans,mx);
        // if(n==1)cout<<ans<<'\n';
        // else cout<<ans+mx<<'\n';

    }

    return 0;
}