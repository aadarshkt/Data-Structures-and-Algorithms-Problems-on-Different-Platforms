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
        int n,m;cin>>n>>m;
        vector<int> a(n);
        for(auto &x:a)cin>>x;
        sort(begin(a),end(a));
        vector<int> pre(n);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            pre[i]=sum;
        }
        for(int i=0;i<n;i++){
            int k=i+1;
            int d=k/m;
            if(k%m>0)d++;
            int las=k%m;
        }
    }

    return 0;
}