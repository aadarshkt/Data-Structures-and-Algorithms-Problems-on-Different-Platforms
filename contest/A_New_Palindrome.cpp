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
        char c=s[0];
        int ans=0;
        for(int i=0;i<n/2;i++){
            if(s[i]!=c)ans=1;
        }
        if(ans)cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }

    return 0;
}