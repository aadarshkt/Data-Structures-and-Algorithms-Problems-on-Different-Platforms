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

    int n,m;cin>>n>>m;
    vector<int> h(n);
    for(auto &x:h)cin>>x;
    vector<vector<int>> dp(n,vector<int>(ceil(log2(n))+1,0));
    for(int i=0;i<n;i++){
        dp[i][0]=h[i];
    }
    for(int j=1;j<=ceil(log2(n));j++){
        for(int i=0;i+(1<<(j))-1<n;i++){
            dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
        }
    }
    int cnt=0;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        a--,b--;
        if(a!=b){
            b--;
        }
        int len=b-a+1;
        int k=log2(len);//maximum power that is less than query length;
        int mx=max(dp[a][k],dp[b-(1<<k)+1][k]);
        dbg(mx);
        if(mx==h[a])cnt++;
    }
    cout<<cnt<<"\n";

    return 0;
}