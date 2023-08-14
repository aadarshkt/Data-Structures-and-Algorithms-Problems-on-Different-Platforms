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
        sort(begin(a),end(a));
        vector<int> b,c;
        int mx=a[n-1];
        for(int i=0;i<n;i++){
            if(a[i]==mx)c.push_back(a[i]);
            else b.push_back(a[i]);
        }
        if((int)b.size()==(int)0)cout<<-1<<'\n';
        else{
            cout<<(int)b.size()<<' '<<(int)c.size()<<'\n';
            for(auto x:b)cout<<x<<' ';
            cout<<'\n';
            for(auto x:c)cout<<x<<' ';
            cout<<'\n';
        }
    }

    return 0;
}