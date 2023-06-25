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

    int n,c;cin>>n>>c;
    vector<int> w(n);
    for(auto &x:w)cin>>x;
    vector<pair<int,int>> dp(1<<n,{n+1,0});
    dp[0]={1,0};//first minimum number of rides for given s and last weight filled of the lift.
    for(int s=1;s<(1<<n);s++){
        for(int i=0;i<n;i++){
            if(s&(1<<i)){
                auto prev=dp[s^(1<<i)];//already calculated lower mask.
                //Take best possible answers of every solution that is built from every submask.Submask is built from considering 
                // one person at a time.
                pair<int,int> curr;
                if(prev.second+w[i]<=c){
                    curr.second=prev.second+w[i];
                    curr.first=prev.first;
                }else{
                    curr.first=prev.first+1;
                    curr.second=w[i];
                }
                dp[s]=min(dp[s],curr);
            }
        }
    }
    cout<<dp[(1<<n)-1].first<<'\n';

    return 0;
}