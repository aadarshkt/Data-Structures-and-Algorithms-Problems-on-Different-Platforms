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
    vector<int> a(n);
    int sum=0;
    for(auto &x:a)cin>>x,sum+=x;
    vector<int> dp(sum+1,0);
    for(int i=0;i<n;i++){
        for(int j=sum;j>=0;j--){
            if(dp[j])dp[j+a[i]]=1;
        }
        dp[a[i]]=1;
    }
    vector<int> ans;
    for(int i=0;i<=sum;i++){
        if(dp[i])ans.push_back(i);
    }
    cout<<(int)ans.size()<<'\n';
    for(auto x:ans)cout<<x<<' ';

    return 0;
}