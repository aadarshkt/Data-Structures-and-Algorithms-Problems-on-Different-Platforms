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
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        v.push_back({a,1});
        v.push_back({b,-1});
    }
    sort(begin(v),end(v));
    int curr=0,mx=0;
    for(pair<int,int> &t:v){
        curr+=t.second;
        mx=max(mx,curr);
    }
    cout<<mx<<'\n';
    return 0;
}