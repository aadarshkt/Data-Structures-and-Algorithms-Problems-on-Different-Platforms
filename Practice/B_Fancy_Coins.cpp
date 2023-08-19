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
        int m,k,a1,ak;cin>>m>>k>>a1>>ak;
        if(ak*k>=m){
            int r=m%k;
            if(r<=a1)cout<<0<<'\n';
            else{
                cout<<r-a1<<'\n';
            }
        }else{
            int r=m-ak*k;
            if(r<=a1)cout<<0<<'\n';
            else{
                if(a1==0){
                    cout<<r/k+r%k<<'\n';
                    continue;
                }
                int x=0;
                if((r-a1)%k==0)x=(r-a1)/k;
                else{
                    x=(r-a1)/k;
                    x++;
                }
                r-=x*k;
                cout<<x<<'\n';
            }
        }
    }

    return 0;
}