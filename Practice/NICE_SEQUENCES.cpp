#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

const int mod=1e9+7;
int dp[1<<10][1001];
int sol(int mask,int i,int n,map<int,vector<int>> &mp){
    if(i==n)return dp[mask][i]=1;
    if(dp[mask][i]!=-1)return dp[mask][i];
    int ans=0;
    for(int j=0;j<=9;j++){
        if(j==1)continue;
        if(j==0){
            (ans+=sol(mask,i+1,n,mp))%=mod;
        }else{
            int sz=mp[j].size();
            for(int k=0;k<sz;k++){
                int divisor=mp[j][k];
                if(mask&(1<<divisor)){
                    (ans+=sol(mask|(1<<j),i+1,n,mp))%=mod;
                    break;
                }
            }
        }
    }
    return dp[mask][i]=ans%mod;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    map<int,vector<int>> mp;
    while(t--){
        int n;cin>>n;
        memset(dp,-1,sizeof(dp));
        for(int i=2;i<=9;i++){
            int dig=i;
            int j=2;
            while(dig/j!=0){
                if(dig%j==0)mp[i].push_back(j);
                j++;
            }
        }
        int ans=0;
        for(auto x:mp)dbg(x.second);
        for(int i=2;i<=9;i++){
            (ans+=sol(1<<i,1,n,mp))%=mod;
        }
        cout<<(ans+1)%mod<<'\n';
    }

    return 0;
}