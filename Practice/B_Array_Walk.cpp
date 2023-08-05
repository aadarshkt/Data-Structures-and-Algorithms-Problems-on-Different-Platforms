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
        int n,k,z;cin>>n>>k>>z;
        vector<int> a(n);
        for(auto &x:a)cin>>x;
        int left=z;
        vector<int> prev;
        for(int i=1;i<n;i++){
            prev.push_back(a[i-1]);
        }
        sort(rbegin(prev),rend(prev));
        vector<int> pre(n-1);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=prev[i];
            pre[i]=sum;
        }
        int rit=k-2*z;

    }

    return 0;
}