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
        int i=0,op=0;
        while(i<n){
            if(i+1<n&&(a[i]+1==a[i+1]||a[i]+2==a[i+1]||a[i]==a[i+1])){
                op++;
                i+=2;
            }else{
                op++;
                i++;
            }
        }
        cout<<op<<'\n';
    }

    return 0;
}