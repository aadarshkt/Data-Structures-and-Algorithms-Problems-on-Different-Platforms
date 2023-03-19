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
    vector<int> arr(n);
    for(auto &x:arr)cin>>x;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        if(mp.count(arr[i]-1)){
            mp[arr[i]]=1;
            mp[arr[i]-1]=0;
        }else{
            mp[arr[i]]=1;
        }
    }
    int ans=0;
    for(auto x:mp){
        if(x.second==1){
            ans++;
        }
    }
    cout<<ans<<'\n';

    return 0;
}