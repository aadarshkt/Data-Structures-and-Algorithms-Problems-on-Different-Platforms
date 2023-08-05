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
        vector<int> a(n);
        int sum=0;
        for(auto &x:a){
            cin>>x;
        }
        for(int i=0;i<n;i++){
            if(i%2==0)sum+=a[i];
        }
        vector<int> dp(n,0);
        for(int i=1;i<n;i++){
            if(i%2!=0){
                dp[i]=a[i]-a[i-1];
            }else{
                dp[i]+=a[i-1]-a[i];
               
            }
        }
        int sum1=0,sum2=0,mx1=0,mx2=0;
        for(int i=0;i<n;i++){
            if(i%2!=0){
                sum1+=dp[i];
                mx1=max(mx1,sum1);
                if(sum1<0)sum1=0;
            }else{
                sum2+=dp[i];
                mx2=max(mx2,sum2);
                if(sum2<0)sum2=0;
            }
        }
        cout<<sum+max(mx1,mx2)<<'\n';
    }

    return 0;
}