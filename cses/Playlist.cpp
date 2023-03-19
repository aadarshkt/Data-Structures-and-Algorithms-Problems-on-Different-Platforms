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
    vector<int> v(n);
    for(auto &x:v)cin>>x;
    map<int,int> mp;
    int ans=0;
    int j=-1;
    for(int i=0;i<n;i++){
        if(mp.count(v[i])&&mp[v[i]]>j){
            j=mp[v[i]];
            ans=max(ans,i-j);
        }else{
            mp[v[i]]=i;
            ans=max(ans,i-j);
        }
    }
    cout<<ans<<'\n';

    return 0;
}