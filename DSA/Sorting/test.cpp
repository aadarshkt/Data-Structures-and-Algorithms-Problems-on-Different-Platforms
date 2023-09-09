#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

bool sortByCond(const pair<int,int> &a,const pair<int,int> &b){
    if(a.first!=b.first)
        return a.first < b.first;
    else
        return a.second > b.second;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        int u,v;cin>>u>>v;
        a[i].first=u,a[i].second=v;
    }
    sort(a.begin(),a.end(),sortByCond);
    for(auto i:a)cout<<i.first<<' '<<i.second<<'\n';
    

    return 0;
}