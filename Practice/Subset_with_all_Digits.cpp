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
        int n,d;cin>>n>>d;
        vector<int> mas;
        for(int i=0;i<n;i++){
            string s;cin>>s;
            int mask=0;
            for(int j=0;j<(int)s.length();j++){
                int single=s[j]-'0';
                mask|=(1<<single);
            }
            mas.push_back(mask);
        }
        vector<int> dp(1<<10,INT_MAX);
        dp[0]=0;
        for(int i=0;i<n;i++){
            for(int mask=0;mask<(1<<10);mask++){
                dp[mask|mas[i]]=min(dp[mask]+1,dp[mask|mas[i]]);
            }
        }
        int ans=dp[(1<<10)-1];
        if(ans==INT_MAX)cout<<-1<<'\n';
        else cout<<ans<<'\n';
    }

    return 0;
}