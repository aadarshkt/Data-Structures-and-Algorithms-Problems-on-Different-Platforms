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
        int c,m,x;cin>>c>>m>>x;
        int te=0;
        te+=min({c,m,x});
        c-=te,m-=te,x-=te;
        if(c==0||m==0)cout<<te<<'\n';
        else{
            int mx=max(c,m),mn=min(c,m);
            if(mx>=2*mn)te+=mn;
            else{
                te+=(mn+mx)/3;
            }
            cout<<te<<'\n';
        }
    }

    return 0;
}