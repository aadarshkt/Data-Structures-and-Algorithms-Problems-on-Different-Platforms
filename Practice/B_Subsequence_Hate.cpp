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
        string s;cin>>s;
        int n=s.length();
        vector<int> pre0(n),suf0(n),pre1(n),suf1(n);
        int o=0,z=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1')o++;
            else z++;
            pre1[i]=o,pre0[i]=z;
        }
        z=0,o=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1')o++;
            else z++;
            suf1[i]=o,suf0[i]=z;
        }
        int ans=n+1;
        for(int i=0;i<n;i++){
            if(i-1>=0)ans=min(ans,pre0[i-1]+suf1[i]);
            else ans=min(ans,suf1[i]);
            if(i-1>=0)ans=min(ans,pre1[i-1]+suf0[i]);
            else ans=min(ans,suf0[i]);
        }
        cout<<ans<<'\n';
    }

    return 0;
}