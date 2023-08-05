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
    vector<vector<double>> a(n,vector<double>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    vector<double> dp((1<<n),0);
    dp[(1<<n)-1]=1;
    for(int mask=(1<<n)-2;mask>0;mask--){
        int cnt=__popcount(mask);//number of alive fish for a mask.
        for(int k=0;k<n;k++){
            if(!((1<<k)&mask))continue;
            for(int j=0;j<n;j++){
                if((1<<j)&mask)continue;
                dp[mask]+=dp[mask|(1<<j)]*a[k][j]/(((cnt)*(cnt+1))/2);
            }
        }
    }
    dbg(dp);
    for(int i=0;i<n;i++){
        printf("%.6lf ",dp[1<<i]);
    }

    return 0;
}