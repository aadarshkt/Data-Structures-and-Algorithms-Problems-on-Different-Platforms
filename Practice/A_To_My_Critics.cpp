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
        int a,b,c;cin>>a>>b>>c;
        int ans=0;
        if(a+b>=10){
            ans=1;
        }else if(b+c>=10){
            ans=1;
        }else if(a+c>=10){
            ans=1;
        }
        if(ans)cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }

    return 0;
}