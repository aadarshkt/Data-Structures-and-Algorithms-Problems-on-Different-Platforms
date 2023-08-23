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
        vector<pair<int,int>> a(n);
        map<int,int> f;
        for(int i=0;i<n;i++){
            cin>>a[i].first;
            a[i].second=i;
            f[a[i].first]++;
        }
        sort(begin(a),end(a));
        dbg(a);
        vector<int> dp(1001,0);
        dp[0]=1;
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            if(dp[a[i].first])ans[a[i].second]=1;
            for(int j=1000;j>=0;j--){
                if(dp[j]&&j+a[i].first<1001)dp[j+a[i].first]=1;
            }
        }
        for(int i=0;i<n;i++){
            if(f[a[i].first]>1)ans[a[i].second]=1;
        }
        for(auto x:ans)cout<<x<<' ';
        cout<<'\n';
    }

    return 0;
}