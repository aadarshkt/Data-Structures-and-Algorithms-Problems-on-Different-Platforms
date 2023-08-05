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
        vector<int> v(n);
        for(auto &x:v)cin>>x;
        int ans=0;
        for(int i=0;i<n;i++){
            int mn=v[i],mx=v[i];
            for(int j=i+1;j<n;j++){
                if(v[j]<mx)ans+=j-i;
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}