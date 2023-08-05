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
        vector<int> v(n),pre(n),suf(n);
        for(auto &x:v)cin>>x;
        sort(begin(v),end(v));
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=v[i];
            pre[i]=sum;
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=v[i];
            suf[i]=sum;
        }
        int mx=0;
        for(int i=0;i<=k;i++){
            int r=n-(k-i)-1;
            int l=2*i-1;
            if(l<0)mx=max(mx,pre[r]);
            else mx=max(mx,pre[r]-pre[l]);
            
        }
        cout<<mx<<'\n';
    }

    return 0;
}