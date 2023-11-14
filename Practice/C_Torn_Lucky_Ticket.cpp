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

    int n;cin>>n;
    vector<vector<int>> dp(7,vector<int>(50,0));
    vector<string> v;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        v.push_back(s);
        int sum=0;
        int sz=s.length();
        for(int j=0;j<sz;j++){
            sum+=(s[j]-'0');
        }
        dp[sz][sum]++;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int sz=v[i].length();
        int sum=0;
        for(int j=0;j<sz;j++){
            sum+=v[i][j]-'0';
        }
        int cnt=0;
        for(int j=0;j<sz;j++){
            cnt+=v[i][j]-'0';
            for(int k=1;k<sz;k++){
                if((j+1)==sz-(j+1)+k){
                    if(2*cnt-sum>0)ans+=dp[k][2*cnt-sum];
                }
                if(k+(j+1)==sz-(j+1)){
                    if(sum-2*cnt>0)ans+=dp[k][sum-2*cnt];
                }
            }
        }
        ans+=dp[sz][sum];
    }
    cout<<ans<<'\n';

    return 0;
}