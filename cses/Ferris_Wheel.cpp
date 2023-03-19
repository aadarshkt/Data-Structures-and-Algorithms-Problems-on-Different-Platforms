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

    int n,x;cin>>n>>x;
    vector<int> arr(n);
    for(auto &ele:arr)cin>>ele;
    sort(begin(arr),end(arr));
    int i=0,j=n-1,ans=0;
    while(i<=j){
        if(i==j){
            ans++;
            break;
        }
        if(arr[i]+arr[j]<=x){
            i++,j--;
            ans++;
        }else{
            j--;
            ans++;
        }
    }
    cout<<ans<<'\n';
    return 0;
}