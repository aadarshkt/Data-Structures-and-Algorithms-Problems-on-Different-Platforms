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
        int x,y,k;cin>>x>>y>>k;
        if(x>y){
            cout<<x<<'\n';
        }else{
            int ans=min(y-x,k);
            ans+=x;
            ans+=2*(y-x-min(y-x,k));
            cout<<ans<<'\n';

        }
    }

    return 0;
}