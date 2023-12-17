#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

//basic idea -> Jump from any node can be decomposed into powers of 2.
//for eg -> you want to jump x units from node y.
//then x can be expressed as sum of powers of 2.(binary representation)
//Now, to find it, you need to know where you will reach after jumping every power of 2 from particular node.
//In short find every power of 2 jump from every node.
//So if you want to jump to x units from node y, then lets say x binary representation is 1 1 1 0
//then if you know for every node every power of 2 jump destination
//then to jump from x
//you need to jump 2^(1) then from there 2^(2) then from there 2^(3), then your destination is reached in cei(log(x)) time.

//dynamic programming comes when to calculate a higher power of 2 you need to jump 2 time lower power of 2.

//dp[i][j] --> you need to caculate where you will reach by jumping from node i a jump of 2^(j);
//to calculate it just jump two 2^(j-1), like 4 + 4 = 8;
//thus dp[i][j] = dp[dp[i][j-1]][j-1];
//lower powers of 2 need to be calculated first.

vector<vector<int>> adj;
vector<vector<int>> dp;
vector<int> par,vis;

void dfs(int s){
    vis[s] = 1;
    for(int x:adj[s]){
        if(vis[x])continue;
        par[x] = s;
        dfs(x);
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;cin>>n>>m;
    adj.resize(n+1);
    for(int i=0;i<=n;i++)adj[i].clear();

    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int max_jump = ceil(log2(n));
    //n - binary representation -- next higher bit ka log value represents total bits needed to represent whole number n.
    //2^(j)>=n solve this, how much j is sufficient to create a value greater than n, take log both sides.

    dp.resize(n+1,vector<int>(max_jump,0));

    //need of parent array
    par.resize(n+1,-1);
    //par[i] -> parent of ith node.

    //dfs is need
    //thus vis is also needed.
    
    //loop through all nodes for disconnected components
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        dfs(i);
    }

    //just jump 2^(0) = 1, you will go to parent.
    //lower power of 2 calculated, now go for higher
    for(int i=1;i<=n;i++){
        dp[i][0] = par[i];
    }

    for(int j=1;j<31;j++){
        for(int i=1;i<=n;i++){
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }

    //ready for jumping.
    int k;cin>>k;
    int starting_node;cin>>starting_node;

    int curr = starting_node;

    for(int i=0;i<31;i++){
        if(k&(1<<i)){
            curr = dp[curr][i];
        }
        if(curr==-1)break;//can't jump this amount;
    }
    cout<<curr<<'\n';


    return 0;
}