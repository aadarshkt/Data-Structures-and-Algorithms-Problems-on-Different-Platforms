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
        int n,m;cin>>n>>m;
        if(m==1){cout<<"YES"<<'\n';continue;}
        if(n%2==0&&m>1)cout<<"NO"<<'\n';
        else{
            if(n%m==0)cout<<"NO"<<'\n';
            else{
                if(n<m){
                    if(n==1)cout<<"YES"<<'\n';
                    else cout<<"NO"<<'\n';
                }else{
                    
                }
            }
        }
    }

    return 0;
}