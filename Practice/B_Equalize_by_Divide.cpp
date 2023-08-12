#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

void calc(int i,int j,vector<pair<int,int>> &a,vector<pair<int,int>> &ans){
    while(a[i].first>a[j].first||a[i].first<a[j].first){
        if(a[i].first>a[j].first){
            int q=ceil(double(a[i].first)/a[j].first);
            a[i].first=q;
            ans.push_back({a[i].second,a[j].second});
        }else if(a[i].first<a[j].first){
            int q=ceil(double(a[j].first)/a[i].first);
            a[j].first=q;
            ans.push_back({a[j].second,a[i].second});
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        for(auto &x:a)cin>>x;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({a[i],i+1});
        }
        sort(begin(a),end(a));
        sort(begin(v),end(v));
        if(a[0]==a[n-1]){
            cout<<0<<'\n';
            continue;
        }
        int fl=1;
        for(int i=0;i<n;i++){
            if(a[i]==1){
                fl=0;break;
            }
        }
        if(!fl){
            cout<<-1<<'\n';
            continue;
        }
        vector<pair<int,int>> ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                calc(i,j,v,ans);
            }
        }
        cout<<(int)ans.size()<<'\n';
        for(auto i:ans)cout<<i.first<<' '<<i.second<<'\n';
    }

    return 0;
}