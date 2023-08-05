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

    int n,k;cin>>n>>k;
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    sort(begin(a),end(a));
    int s=n/2;
    int lo=0,hi=1e10;
    while(hi-lo>1){
        int mid=lo+(hi-lo)/2;
        int sum=0;
        for(int i=s;i<n;i++){
            if(mid>a[i])sum+=mid-a[i];
        }
        if(sum<=k)lo=mid;
        else hi=mid;
    }
    cout<<lo<<'\n';

    return 0;
}