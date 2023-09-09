#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

const int mxJump=ceil(log2((int)1e9));
int dp[(int)2e5+5][31];

//answer query
int binaryJump(int u,int k){
    int curr=u;
    for(int j=0;j<=mxJump;j++){
        if(k&(1<<j)){
            curr=dp[curr][j];
        }
        if(curr==-1)break;
    }
    return curr;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;cin>>n>>q;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];

    //preprocessing
    //dp[i][j] --> node that you will reach after you start from i and 1<<j jumps.
    for(int i=1;i<=n;i++){
        dp[i][0]=a[i];
    }
    for(int j=1;j<=mxJump;j++){
        for(int i=1;i<=n;i++){
            dp[i][j]=dp[dp[i][j-1]][j-1];
        }
    }

    //answer queries.
    for(int i=0;i<q;i++){
        int x,k;cin>>x>>k;
        if(a[x]==x)cout<<x<<'\n';
        else cout<<binaryJump(x,k)<<'\n';
    }



    return 0;
}