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
    int a,b,c,d;cin>>a>>b>>c>>d;
    int m=0;
    if(d<b)cout<<-1<<'\n';
    else{
        m+=(d-b);
        a+=(d-b);
        if(c>a)cout<<-1<<'\n';
        else{
            m+=a-c;
            cout<<m<<'\n';
        }
    }
    }

    return 0;
}