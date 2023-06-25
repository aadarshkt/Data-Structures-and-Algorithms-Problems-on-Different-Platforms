#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

bool dfs(vector<vector<int>> &adj,vector<int> &vis,vector<int> &rec,int s,vector<int> &top){
    vis[s]=1;
    rec[s]=1;
    int ans=0;
    for(auto i:adj[s]){
        if(rec[i])ans=1;
        if(!vis[i]){
            ans|=dfs(adj,vis,rec,i,top);
        }
    }
    top.push_back(s);
    rec[s]=0;
    return ans;
}

void relax(vector<vector<int>> &adj,vector<int> &parent,vector<int> &dp,int s){
    for(auto i:adj[s]){
        if(dp[i]<dp[s]+1){
            dp[i]=dp[s]+1;
            parent[i]=s;
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> vis(n+1,0),parent(n+1,-1),rec(n+1,0),top,dp(n+1,INT_MIN);
    dp[1]=0;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
    }
    int pos=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            pos=dfs(adj,vis,rec,i,top);
            if(pos)break;
        }
    }
    dbg(pos);
    if(pos){
        cout<<"IMPOSSIBLE"<<'\n';
        return 0;
    }
    reverse(begin(top),end(top));
    for(auto x:top){
        if(dp[x]==INT_MIN)continue;
        relax(adj,parent,dp,x);
    }
    if(dp[n]==INT_MIN){
        cout<<"IMPOSSIBLE"<<'\n';
        return 0;
    }
    vector<int> ans;
    ans.push_back(n);
    int s=parent[n];
    while(s!=-1){
        ans.push_back(s);
        s=parent[s];
    }
    reverse(begin(ans),end(ans));
    cout<<(int)ans.size()<<"\n";
    for(auto x:ans)cout<<x<<' ';

    return 0;
}