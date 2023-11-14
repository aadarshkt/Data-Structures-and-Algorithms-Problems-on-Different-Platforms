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
        int n;cin>>n;
        string s;cin>>s;
        int cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(s[i]=='A')cnt1++;
            else cnt2++;
        }
        if(cnt1>cnt2)cout<<'A'<<'\n';
        else if(cnt2>cnt1)cout<<'B'<<'\n';
        else cout<<'?'<<'\n';
    }

    return 0;
}