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

    int t;
    cin >> t;
    while(t--){
        int n;cin>>n;
        vector<int> v(n),dp(n,0);
        for(auto &x:v)cin>>x;
        map<int,int> mp;
        mp[v[0]]=0;
        for(int i=1;i<n;i++){
            if(!mp.count(v[i])){
                mp[v[i]]=i;
                if(i-1>=0)dp[i]=dp[i-1];
            }else{
                int l=mp[v[i]],r=i;
                if(l-1>=0){
                    int val1=dp[i-1],val2=dp[l-1]+r-l+1;
                    if(val1>=val2){
                        mp[v[i]]=i;
                        dp[i]=val1;
                    }else{
                        dp[i]=val2;
                    }
                }else{
                    int val1=dp[i-1],val2=r-l+1;
                    if(val1>=val2){
                        mp[v[i]]=i;
                        dp[i]=val1;
                    }else{
                        dp[i]=val2;
                    }
                }
            }
        }
        cout<<dp[n-1]<<'\n';

    }

    return 0;
}