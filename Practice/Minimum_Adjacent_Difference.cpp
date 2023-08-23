#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

//fl --> is previous swapped or not.

int dp[(int)1e5+1][2];
// int solve(vector<int> &a,vector<int> &b,int mx,int op,int k,int i,int n,int fl){
//     if(i==n){
//         return dp[i][fl]=mx;
//     }
//     if(dp[i][fl]!=-1)return dp[i][fl];
//     int res=INT_MAX;
//     if(op<k){
//         if(fl){
//             int mx1=max(mx,abs(b[i-1]-b[i])),mx2=max(mx,abs(b[i-1]-a[i]));
//             res=min(solve(a,b,mx1,op+1,k,i+1,n,1),solve(a,b,mx2,op,k,i+1,n,0));
//         }else{
//             int mx1=max(mx,abs(a[i-1]-b[i])),mx2=max(mx,abs(a[i-1]-a[i]));
//             res=min(solve(a,b,mx1,op+1,k,i+1,n,1),solve(a,b,mx2,op,k,i+1,n,0));
//         }
//     }else{
//         if(fl){
//             int mx1=max(mx,abs(b[i-1]-a[i]));
//             res=solve(a,b,mx1,op,k,i+1,n,0);
//         }else{
//             int mx1=max(mx,abs(a[i-1]-a[i]));
//             res=solve(a,b,mx1,op,k,i+1,n,0);
//         }
//     }
//     return dp[i][fl]=res;
// }

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        int n,k;cin>>n>>k;
        vector<int> a(n),b(n);
        for(auto &x:a)cin>>x;
        for(auto &x:b)cin>>x;
        int ans=INT_MAX,mx=INT_MIN;
        ans=min(solve(a,b,mx,0,k,1,n,0),solve(a,b,mx,1,k,1,n,1));
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++)cout<<dp[i][j]<<' ';
        }
        cout<<'\n';
        cout<<ans<<'\n';
    }

    return 0;
}