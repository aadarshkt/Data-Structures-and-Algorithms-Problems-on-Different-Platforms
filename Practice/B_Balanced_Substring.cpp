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
    string s;cin>>s;
    map<int,int> mp;
    int val=0,ans=0;
    mp[0]=-1;
    for(int i=0;i<n;i++){
        if(s[i]=='0')val++;
        else val--;
        if(mp.count(val)){
            ans=max(i-mp[val],ans);
        }else mp[val]=i;
    }
    cout<<ans<<'\n';

    return 0;
}