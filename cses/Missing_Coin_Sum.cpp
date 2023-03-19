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
    sort(begin(arr),end(arr));
    int sum=0,ans=0;
    for(int i=0;i<n;i++){
        int diff=arr[i]-sum;
        if(diff>1){
            ans=sum+1;
            break;
        }
        sum+=arr[i];
    }
    if(ans==0)cout<<sum+1<<'\n';
    else cout<<ans<<'\n';
    return 0;
}