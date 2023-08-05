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
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    map<int,int> mp;
    vector<pair<int,int>> f;
    for(int i=0;i<n;i++){
        mp[a[i]]++;
    }
    for(auto x:mp){
        f.push_back({x.second,x.first});
    }
    sort(rbegin(f),rend(f));
    dbg(f);
    int sz=f.size();
    int lo=0,hi=f[0].first+1;
    vector<int> t;
    int fl=0;
    while(hi-lo>1){
        int mid=lo+(hi-lo)/2;
        dbg(mid);
        int sum=0;
        vector<int> temp;
        fl=0;
        for(int i=0;i<sz;i++){
            int q=f[i].first/mid;
            sum+=q;
            dbg(q);
            if(sum>=k){
                int ts=temp.size();
                if(ts<k){
                    for(int j=0;j<k-ts;j++){
                        temp.push_back(f[i].second);
                    }
                }
                fl=1;
                break;
            }
            while(q--){
                temp.push_back(f[i].second);
            }
        }
        if(fl){
            lo=mid;
            t=temp;
        }
        else hi=mid;
    }
    for(auto x:t)cout<<x<<' ';

    return 0;
}