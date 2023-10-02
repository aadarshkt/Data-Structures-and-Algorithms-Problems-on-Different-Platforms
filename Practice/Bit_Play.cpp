#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

const int mod=1e9+7;

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        int ans=1;
        for(int i=0;i<n-2;i+=2){
            int cnt=0;
            int b1=s[i]-'0',b2=s[i+1]-'0',b3=s[i+2]-'0';
            if((b1^b2)==b3)cnt++;
            if((b1&b2)==b3)cnt++;
            if((b1|b2)==b3)cnt++;
            (ans*=cnt)%=mod;
            dbg(b1,b2,b3);
        }
        cout<<ans<<'\n';
       
    }

    return 0;
}