#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

bool check(int x){
        double d=log(x)/log(5);
        int q=d;
        if(abs(q-d)==0)return 1;
        return 0;
    }

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;cin>>n;
        int ans=0;
        for(int i=0;i<n;i++){
            int a,b;cin>>a>>b;
            if(a-b<=0)ans++;
        }
        cout<<n-ans<<'\n';
        dbg(check(125));
    }

    return 0;
}