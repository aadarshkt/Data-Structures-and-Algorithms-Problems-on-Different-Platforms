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
        int a,b;cin>>a>>b;
        if(a==b){
            if(a%3==0)cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }else{
            int diff=max(a,b)-min(a,b);
            if(min(a,b)-diff>=0){
                int small=min(a,b)-diff;
                if(small%3==0)cout<<"YES"<<'\n';
                else cout<<"NO"<<'\n';
            }else cout<<"NO"<<'\n';
        }
    }

    return 0;
}