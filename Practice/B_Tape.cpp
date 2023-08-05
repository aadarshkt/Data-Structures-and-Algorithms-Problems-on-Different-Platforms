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

    int n,m,k;cin>>n>>m>>k;
    vector<int> b(n);
    for(auto &x:b)cin>>x;
    if(n<=k){
        cout<<n<<'\n';
        return 0; 
    }
    vector<int> diff;
    for(int i=0;i<n-1;i++){
        diff.push_back(b[i+1]-b[i]);
    }
    sort(begin(diff),end(diff));
    int req=n-k;
    int ans=n;
    for(int i=0;i<n-1;i++){
        ans+=diff[i]-1;
        req--;
        if(req==0)break;
    }
    cout<<ans<<'\n';

    return 0;
}