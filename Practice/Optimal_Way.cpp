#include <bits/stdc++.h>
using namespace std;

int dp[21][1<<20];
int solve(vector<int> &a,int i,int k,int n,int mask){
    if(i==k)return 0;
    if(dp[i][mask]!=-1)return dp[i][mask];
    int ans=0;
    for(int j=0;j<n;j++){
        if(mask&(1<<j))continue;
        for(int l=j+1;l<n;l++){
            if(mask&(1<<l))continue;
            ans=max(ans,(i+1)*(a[j]&a[l])+solve(a,i+1,k,n,mask|(1<<j)|(1<<l)));
        }
    }
    return dp[i][mask]=ans;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n;cin>>n;
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    int k;cin>>k;
    cout<<solve(a,0,k,n,0)<<'\n';
    return 0;
}