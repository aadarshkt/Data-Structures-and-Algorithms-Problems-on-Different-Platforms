#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

//fl is 0 when non-zero number has not come.
//fl is 1 when non-zero number has come.
//prev is the prev digit.
//t is tight value to show that whether we can take full values upto 9 or not.
//if t is one means we can take only upto a[i]
//if t is zero means we cant take upto 9

int dp[20][2][2][10];

int solve(string a,int n,int i,int t,int fl,int prev){
    if(i==n)return 1;
    if(dp[i][t][fl][prev]!=-1)return dp[i][t][fl][prev];
    int last=t==1?a[i]-'0':9;
    int ans=0;
    for(int j=0;j<=last;j++){
        int nt=1;//newTight value.
        if(t&&j==last)nt=1;
        else nt=0;
        if(fl){
            if(j!=prev){
                ans+=solve(a,n,i+1,nt,fl,j);
            }
        }else{
            if(j==0){
                ans+=solve(a,n,i+1,nt,0,j);
            }else{
                ans+=solve(a,n,i+1,nt,1,j);
            }
        }
    }
    return dp[i][t][fl][prev]=ans;
}

int calc(int n){
    string num=to_string(n);
    return solve(num,(int)num.length(),0,1,0,-1);
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b;cin>>a>>b;
    memset(dp,-1,sizeof(dp));
    int ans=calc(b);
    memset(dp,-1,sizeof(dp));
    if(a>0)ans-=calc(a-1);
    cout<<ans<<'\n';

    return 0;
}