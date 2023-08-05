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
        int sum=0;
        for(auto &x:a){
            cin>>x;
            sum+=x;
        }
        sort(begin(a),end(a));
        int p=0;
        for(int i=0;i<n;i++){
            cout<<sum<<' ';
            sum-=a[p];
            p++;
        }
        cout<<'\n';
    }

    return 0;
}