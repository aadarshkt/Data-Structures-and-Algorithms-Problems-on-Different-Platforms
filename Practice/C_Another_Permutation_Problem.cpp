#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

pair<int,int> fun(int n,int i){
    int mx=n;
    pair<int,int> res={0,INT_MIN};
    for(int j=i;j<=n;j++){
        res.first+=(j)*(mx);
        res.second=max(res.second,j*mx);
        mx--;
    }
    for(int j=1;j<i;j++){
        res.first+=j*j;
        res.second=max(res.second,j*j);
    }
    return res;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++){
            dbg(fun(n,i));
            ans=max(ans,fun(n,i).first-fun(n,i).second);
        }
        cout<<ans<<'\n';
    }

    return 0;
}