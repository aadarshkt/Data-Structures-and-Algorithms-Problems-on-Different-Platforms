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

    string s1,s2;cin>>s1>>s2;
    int n1=s1.length(),n2=s2.length();
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
    //base case;
    for(int i=0;i<=n2;i++){
        dp[0][i]=i;
    }
    for(int i=0;i<=n1;i++){
        dp[i][0]=i;
    }
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1];
            else{
                dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
            }
        }
    }
    cout<<dp[n1][n2];

    return 0;
}