#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int solve(vector<int> &weight,int mask,int lastWeight,int capacity,int n,vector<vector<int>> &dp){
    if(mask==0)return 1;
    if(dp[mask][lastWeight]!=-1)return dp[mask][lastWeight];
    int ans=n+1;
    for(int i=0;i<n;i++){
        if(mask&(1<<i)){
            if(weight[i]>capacity)continue;
            if(lastWeight+weight[i]<=capacity){
                ans=min(ans,solve(weight,mask^(1<<i),lastWeight+weight[i],capacity,n,dp));
            }else{
                ans=min(ans,1+solve(weight,mask^(1<<i),weight[i],capacity,n,dp));
            }
        }
    }
    return dp[mask][lastWeight]=ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,capacity;cin>>n>>capacity;
    vector<int> weight(n,0);
    for(auto &x:weight)cin>>x;
    vector<vector<int>> dp(1<<n,vector<int>(capacity+1,-1));
    cout<<solve(weight,(1<<n)-1,0,capacity,n,dp)<<'\n';

    return 0;
}