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

    int n;cin>>n;
    vector<int> arr(n);
    for(auto &x:arr)cin>>x;
    int ans=0;
    for(int i=0;i<n-1;i++){
        int diff=arr[i+1]-arr[i];
        if(diff<0){
            ans+=abs(diff);
            arr[i+1]=arr[i];
        }
    }
    dbg(arr);
    cout<<ans<<'\n';

    return 0;
}