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
        int b,c,h;cin>>b>>c>>h;
        int l=2;
        b-=2;
        int req=c+h-1;
        if(b<req){
            l+=b;
            l+=(b+1);
        }else{
            l+=c+h;
            l+=req;
        }
        cout<<l<<'\n';
    }

    return 0;
}