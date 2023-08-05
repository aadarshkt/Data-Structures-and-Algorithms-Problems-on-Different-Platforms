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
    vector<vector<int>> adj(n,vector<int>(n,0));
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        u--,v--;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    //mask represents subset
    //dp[i][mask] represents whether or not you can visit every set bit of mask exactly once
    // and end i.
    vector<vector<int>> dp(n,vector<int>((1<<n),0));
    for(int i=0;i<n;i++){
        dp[i][1<<i]=1;
        //i == 0 represents first location.
    }
    for(int mask=1;mask<(1<<n);mask++){
        //for every set bit(call it j) check wether there is neighbour of that in rest of set bit.
        //if there is neighbour(call it k) then check whether dp[k][mask^(pow(2,j))] is true or not.
        // if true means that you can reach a neighbour of j visiting all nodes without j and then end at k.
        for(int j=0;j<n;j++){
            if(!(mask&(1<<j)))continue;//check which bit is set.
            for(int k=0;k<n;k++){
                if(!(mask&(1<<k)))continue;
                if(j==k)continue;
                if(!adj[j][k])continue;
                if(adj[k][mask^(1<<j)])adj[j][mask]=true;//remove jth bit from mask.
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(dp[i][(1<<n)-1]){
            ans=1;break;
        }
    }
    if(ans)cout<<"YES"<<'\n';
    else cout<<"NO"<<"\n";


    return 0;
}