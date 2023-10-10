#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int dp[5001][5001];

int solve(vector<int> &a,int i,int n,int j,int k){
    if(j==k){
        return 0;
    }
    if(i==n){
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int s=a[i],cnt=0,pos=0;
    for(int p=i+1;p<n;p++){
        if(a[p]-s<=5){
            cnt++;
            pos=p;
        }else break;
    }
    return dp[i][j]=max((pos-i+1)+solve(a,pos+1,n,j+1,k),
    solve(a,i+1,n,j,k));
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;cin>>n>>k;
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    sort(begin(a),end(a));
    memset(dp,-1,sizeof(dp));
    int ans=solve(a,0,n,0,k);
    cout<<ans<<'\n';
    

    return 0;
}