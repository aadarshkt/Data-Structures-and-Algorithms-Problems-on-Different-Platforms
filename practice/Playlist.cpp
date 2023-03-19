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
    int j=-1,ans=0;
    for(int i=0;i<n;i++){
        if(mp.count(arr[i])&&mp[arr[i]]>j){
            j=mp[arr[i]];
            mp[arr[i]]=i;
        }else{
            mp[arr[i]]=i;
        }
        ans=max(ans,i-j);
    }
    cout<<ans<<'\n';

    return 0;
}