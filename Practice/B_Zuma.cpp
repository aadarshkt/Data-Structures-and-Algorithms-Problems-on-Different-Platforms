#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

//provide least value for interval i,j;
int dp[501][501];
int solve(vector<int> &a,int i,int j,int n){
    dbg(i,j);
    if(i==j)return 1;
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=INT_MAX;
    int pos=-1;
    int val1=INT_MAX;
    for(int k=i+2;k<=j;k++){
        if(a[k]==a[i]){
            pos=k;
            val1=min(val1,solve(a,i+1,pos-1,n)+solve(a,pos+1,j,n));
        }
    }
    int val2=1+solve(a,i+1,j,n);
    if(i+1<n&&a[i]==a[i+1]){
        ans=min({ans,val1,val2,1+solve(a,i+2,j,n)});
    }else{
        ans=min({ans,val1,val2});
    }
    return dp[i][j]=ans;

}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    memset(dp,-1,sizeof(dp));
    cout<<solve(a,0,n-1,n)<<'\n';

    return 0;
}