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
        vector<int> v(n);
        for(auto &x:v)cin>>x;
        sort(begin(v),end(v));
        int p1=0,p2=1,p3=n-1;
        while(k){
            if(v[p1]+v[p2]<v[p3]){
                p1+=2;p2+=2;
            }else{
                p3--;
            }
            k--;
        }
        int ans=0;
        for(int i=p1;i<=p3;i++){
            ans+=v[i];
        }
        cout<<ans<<'\n';
    }

    return 0;
}