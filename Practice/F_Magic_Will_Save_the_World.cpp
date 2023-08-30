#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

bool solve(vector<int> &s,int i,int n,int tw,int tf){
    if(i==n)return 1;
    bool ans=false;
    if(tw>=s[i]&&tf>=s[i]){
        ans=solve(s,i+1,n,tw-s[i],tf)|solve(s,i+1,n,tw,tf-s[i]);
    }else if(tw>=s[i]){
        ans=solve(s,i+1,n,tw-s[i],tf);
    }else if(tf>=s[i]){
        ans=solve(s,i+1,n,tw,tf-s[i]);
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int w,f;cin>>w>>f;
        int n;cin>>n;
        vector<int> s(n);
        int sum=0;
        for(auto &x:s)cin>>x,sum+=x;
        vector<int> dp(sum+1,0);
        dp[0]=1;
        //dp[i] --> is i sum possible or not i can be subset(sum) or strengths or not.
        for(int i=0;i<n;i++){
            for(int j=sum;j>=s[i];j--){
                dp[j]=dp[j]||dp[j-s[i]];
            }
        }
        int ans=1e6+1;
        for(int i=0;i<=sum;i++){
            if(dp[i]){
                int d1=ceil(double(i)/w),d2=ceil((double)(sum-i)/f);
                ans=min(ans,max(d1,d2));
            }
        }
        cout<<ans<<'\n';
        
    }

    return 0;
}