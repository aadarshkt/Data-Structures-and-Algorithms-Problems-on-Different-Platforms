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

    int n;cin>>n;
    map<int,vector<int>> mp1;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int c;cin>>c;
        v.push_back({c,i});
        for(int j=0;j<c;j++){
            int a;cin>>a;
            mp1[i].push_back(a);
        }
    }
    sort(begin(v),end(v));
    vector<int> ans;
    int x;cin>>x;
    int mn=40;
    for(auto it:v){
        int idx=it.second;
        for(auto ele:mp1[idx]){
            if(ele==x)mn=min(mn,(int)mp1[idx].size());
        }
    }
    for(auto it:v){
        int idx=it.second;
        for(auto ele:mp1[idx]){
            if(ele==x&&(int)mp1[idx].size()==mn)ans.push_back(idx+1);
        }
    }
    cout<<(int)ans.size()<<'\n';
    for(auto ele:ans)cout<<ele<<' ';

    return 0;
}