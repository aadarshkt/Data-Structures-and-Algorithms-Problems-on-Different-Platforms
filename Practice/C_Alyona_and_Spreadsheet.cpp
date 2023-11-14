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

    int n,m;cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m)),dp(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    vector<int> b(n*m),id(n*m);
    int k=0;
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            b[k]=v[i][j];
            k++;
        }
    }
    dbg(b);
    for(int i=0;i<n*m;i++){
        if(i==0)id[i]=1;
        else{
            if(b[i]>=b[i-1])id[i]=id[i-1];
            else id[i]=id[i-1]+1;
        }
    }
    k=0;
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            auto it=upper_bound(begin(id)+k,end(id),id[k]);
            dp[i][j]=it-begin(id)-k;
            k++;
        }
    }
    vector<int> dp1(n,-1);
    for(int i=0;i<n;i++){
        int mx=-1;
        for(int j=0;j<m;j++){
            mx=max(mx,dp[i][j]);
        }
        dp1[i]=mx;
    }
    int k1;cin>>k1;
    dbg(dp1);
    dbg(dp);
    dbg(id);
    for(int i=0;i<k1;i++){
        int l,r;cin>>l>>r;
        int len=r-l+1;
        l--;
        if(dp1[l]>=len)cout<<"Yes"<<'\n';
        else cout<<"No"<<'\n';
    }
    

    return 0;
}