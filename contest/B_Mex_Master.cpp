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
        int z=0,mx=0,nz=0;
        for(int i=0;i<n;i++){
            if(v[i]==0){
                z++;
            }else nz++;
            mx=max(mx,v[i]);
        }
        if(nz>=z||z-nz==1){
            cout<<0<<'\n';
        }else{
            if(mx>1){
                cout<<1<<'\n';
            }else if(mx==1){
                cout<<2<<'\n';
            }else{
                cout<<1<<'\n';
            }
        }
    }

    return 0;
}