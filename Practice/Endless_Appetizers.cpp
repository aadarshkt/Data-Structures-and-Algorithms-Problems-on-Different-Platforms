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
        int x,y,r;cin>>x>>y>>r;
        int extra=r/30;
        int total=x+extra;
        if(total%y==0)cout<<total/y<<'\n';
        else cout<<((total)/y)+1<<"\n";
    }

    return 0;
}