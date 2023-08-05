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
        int n,m,k,H;cin>>n>>m>>k>>H;
        vector<int> h(n);
        for(auto &x:h)cin>>x;
        int ans=0;
        for(int i=0;i<n;i++){
            int diff=abs(H-h[i]);
            if(diff%k==0){
                int q=diff/k;
                if(q>=1&&q<=m-1)ans++;
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}