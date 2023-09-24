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
        int ans=0;
        int fl=0,fl1=0;
        for(int i=30;i>=0;i--){
            bool val1=0,val2=0;
            if(a&(1<<i))val1=1;
            if(b&(1<<i))val2=1;
            if(fl&&val1!=val2){
                dbg(t,i,val1,val2);
                if(fl1){
                    if(val1==1)ans+=1<<i;
                }else{
                    if(val2==1)ans+=(1<<i);
                }
            }
            if(val1!=val2&&!fl){
                dbg(t,i);
                if(val1==1)fl1=1;
                fl=1;
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}