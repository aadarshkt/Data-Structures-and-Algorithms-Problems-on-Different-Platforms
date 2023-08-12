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
        vector<int> a(n);
        for(auto &x:a)cin>>x;
        vector<int> cpy;
        for(int i=0;i<n;i++){
            cpy.push_back(a[i]);
        }
        sort(begin(cpy),end(cpy));
        int fl=1;
        int mx=0;
        for(int i=0;i<n;i++){
            if(a[i]!=cpy[i]){
                mx=max(mx,a[i]);
                fl=0;
            }
        }
        if(fl)cout<<0<<'\n';
        else{
            cout<<mx<<'\n';
        }
    }

    return 0;
}