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
        vector<int> bin(n);
        int fl=0;
        for(auto &x:bin){
            cin>>x;
            if(x==0)fl=1;
        }
        if(!fl){
            cout<<0<<'\n';continue;
        }
        int ans=1,cnt=1;
        for(int i=1;i<n;i++){
            if(bin[i]==0&&bin[i-1]==0)cnt++;
            else cnt=1;
            ans=max(ans,cnt);
        }
        cout<<ans<<'\n';
    }

    return 0;
}