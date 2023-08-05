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
        int n;cin>>n;
        if(n%2!=0)cout<<1<<'\n';
        else{
            int ans;
            if(n%3==0){
                ans=3;
                int cnt=1;
                for(int i=2;i<=100;i++){
                    if(n%i==0&&n%(i-1)==0){
                        cnt++;
                    }else cnt=1;
                    ans=max(ans,cnt);
                }  
            }else{
                ans=2;
            }
            cout<<ans<<'\n';
        }
    }

    return 0;
}