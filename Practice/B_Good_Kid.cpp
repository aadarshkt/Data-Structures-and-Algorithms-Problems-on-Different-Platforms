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
        int ans=0;
        vector<int> a(n);
        for(auto &x:a)cin>>x;
        for(int i=0;i<n;i++){
            int mx=1;
            for(int j=0;j<n;j++){
                if(j==i){
                    mx*=(a[j]+1);
                }else mx*=a[j];
            }
            ans=max(ans,mx);
        }
        cout<<ans<<'\n';
    }

    return 0;
}