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
        vector<int> a(n),b(n);
        int sum1=0,sum2=0;
        for(auto &x:a){
            cin>>x;
            sum1+=x;
        }
        for(auto &x:b){
            cin>>x;
            sum2+=x;
        }
        sort(begin(a),end(a));
        sort(begin(b),end(b));
        cout<<min(sum1+n*b[0],sum2+n*a[0])<<'\n';
    }

    return 0;
}