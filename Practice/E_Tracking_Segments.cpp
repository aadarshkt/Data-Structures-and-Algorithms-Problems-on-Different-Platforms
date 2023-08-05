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
        int n,m;cin>>n>>m;
        vector<pair<int,int>> v;
        for(int i=0;i<m;i++){
            int l,r;cin>>l>>r;
            l--,r--;
            v.push_back({l,r});
        }
        int q;cin>>q;
        int lo=-1,hi=q;
        vector<int> qu;
        for(int i=0;i<q;i++){
            int idx;cin>>idx;
            idx--;
            qu.push_back(idx);
        }
        while(hi-lo>1){
            int mid=lo+(hi-lo)/2;
            vector<int> arr(n,0);
            for(int i=0;i<=mid;i++){
                arr[qu[i]]=1;
            }
            int cnt=0;
            vector<int> pre(n);
            for(int i=0;i<n;i++){
                if(arr[i]==1)cnt++;
                pre[i]=cnt;
            }
            int ans=0;
            for(int i=0;i<m;i++){
                int len=v[i].second-v[i].first+1;
                int ones=pre[v[i].second];
                if(v[i].first-1>=0)ones-=pre[v[i].first-1];
                int zero=len-ones;
                if(ones>zero)ans=1;
            }
            if(ans)hi=mid;
            else lo=mid;
        }
        if(hi==q)cout<<-1<<'\n';
        else cout<<hi+1<<"\n";

    }

    return 0;
}