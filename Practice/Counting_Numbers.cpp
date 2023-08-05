#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int dp[20][2][10];
int sol(string s,int n,int i,int t,int prev,int fl){
    if(i==n)return dp[i][t][prev]=1;
    if(dp[i][t][prev]!=-1)return dp[i][t][prev];
    int curr=s[i]-'0';
    int ans=0;
    if(t==1){
        for(int j=0;j<=curr;j++){
            if(j==prev&&fl)continue;
            if(j==curr){
                if(j==0){
                    if(fl)ans+=sol(s,n,i+1,1,j,1);
                    else ans+=sol(s,n,i+1,1,j,0);
                }
                else ans+=sol(s,n,i+1,1,j,1);
            }
            else{
                if(j==0){
                    if(fl)ans+=sol(s,n,i+1,0,j,1);
                    else sol(s,n,i+1,0,j,0);
                }
                else ans+=sol(s,n,i+1,0,j,1);
            }
        }
    }else{
        for(int j=0;j<=9;j++){
            if(j==prev&&fl)continue;
            if(j==0){
                if(fl)ans+=sol(s,n,i+1,0,j,1);
                else ans+=sol(s,n,i+1,0,j,0);
            }
            else ans+=sol(s,n,i+1,0,j,1);
        }
    }
    return dp[i][t][prev]=ans;
}

int calc(int n){
    string s1=to_string(n);
    int n1=s1.length();
    int fir=s1[0]-'0';
    int ans=0;
    for(int i=0;i<=fir;i++){
        string inp=to_string(i)+s1.substr(1,n1-1);
        if(i==fir){
            ans+=sol(inp,n1,1,1,i,1);
        }else{
            if(i==0)ans+=sol(inp,n1,1,0,i,0);    
            else ans+=sol(inp,n1,1,0,i,1);
        }
        dbg(n,inp);
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp,-1,sizeof(dp));
    int a,b;cin>>a>>b;
    int res1=calc(a-1),res2=calc(b);
    dbg(res1,res2);
    cout<<res2-res1<<'\n';

    return 0;
}