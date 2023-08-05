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
        int m=(n-1)/2,diff=-1;
        vector<int> gre;
        for(int i=0;i<=m;i++){
            diff=abs(v[i]-v[n-1-i]);
            gre.push_back(diff);
        }
        int sz=gre.size();
        int gcd=gre[0];
        for(int i=1;i<sz;i++){
            if(gre[i]==0)continue;
            gcd=__gcd(gcd,gre[i]);
        }
        cout<<gcd<<'\n';
    }

    return 0;
}