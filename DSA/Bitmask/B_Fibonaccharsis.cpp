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
        int n,k;cin>>n>>k;
        int prev2=n,prev1;
        int cnt=0;
        for(int i=0;i<=n;i++){
            prev1=i,prev2=n;
            int len=2;
            int fl=1;
            while(len<k){
                int nxt=prev2-prev1;
                if(nxt<0||(nxt>prev1)){
                    fl=0;break;
                }
                prev2=prev1;
                prev1=nxt;
                len++;
            }
            if(fl)cnt++;
        }
        cout<<cnt<<'\n';
    }

    return 0;
}