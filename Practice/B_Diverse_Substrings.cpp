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

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int> mp;
            int mx=0;
            for(int j=i;j<min(i+100,n);j++){
                mp[s[j]]++;
                if(mp[s[j]]>mx)mx=mp[s[j]];
                int sz=mp.size();
                if(mx<=sz)ans++;
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}