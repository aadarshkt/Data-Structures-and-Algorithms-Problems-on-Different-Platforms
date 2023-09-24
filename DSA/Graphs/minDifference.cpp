#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int minimumDifference(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++)sum+=nums[i];
        dbg(sum);
        vector<int> dp(sum+1,0);
        for(int i=0;i<n;i++){
            for(int j=sum;j>=0;j--){
                if(dp[j]&&j+nums[i]<=sum){
                    dp[j+nums[i]]=1;
                }
            }
            dp[nums[i]]=1;
        }
        dbg(dp);
        int ans=INT_MAX;
        for(int i=0;i<=sum;i++){
            if(dp[i]){
                int second=sum-i;
                ans=min(ans,abs(second-i));
            }
        }
        return ans;
    }

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    cout<<minimumDifference(a)<<'\n';

    return 0;
}