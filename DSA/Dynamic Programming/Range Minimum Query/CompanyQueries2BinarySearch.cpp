#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

void bfs(vector<vector<int>> &adj,vector<int> &vis,int s,vector<int> &lev){
    vis[s]=1;
    queue<int> q;
    q.push(s);
    q.push(-1);
    int level=0;
    while(!q.empty()){
        int fr=q.front();
        if(fr==-1){
            while(!q.empty())q.pop();
            continue;
        }
        q.pop();
        lev[fr]=level;
        if(q.front()==-1){
            q.pop();
            level++;
        }
        int fl=0;
        for(auto i:adj[fr]){
            if(vis[i])continue;
            vis[i]=1;
            q.push(i);
            fl=1;
        }
        if(fl)q.push(-1);
    }
}

//returns node after you jump from u node by k levels
int binaryJump(int u,int k,vector<int> &par,int n,int mxJump,vector<vector<int>> &dp){
    dbg(k,mxJump);
    if(k>(1<<mxJump))return -1;
    int curr=u;
    for(int j=0;(1<<j)<=k;j++){
        if(k&(1<<j)){
            dbg(k,j,curr);
            if(6<=1<<mxJump)dbg(dp[6][2]);
            curr=dp[curr][j];
            dbg(k,j,curr);
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
    vector<int> par(n+1,-1);
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int p;cin>>p;
        par[i+2]=p;
        adj[p].push_back(i+2);
        adj[i+2].push_back(p);
    }
    vector<int> lev(n+1,0),vis(n+1,0);
    bfs(adj,vis,1,lev);
    dbg(lev);
    //preprocessing.
    int mxJump=ceil(log2(n-1));
    vector<vector<int>> dp(n+1,vector<int>(mxJump+1,-1));
    for(int i=1;i<=n;i++){
        dp[i][0]=par[i];
    }
    for(int j=1;j<=mxJump;j++){
        for(int i=1;i<=n;i++){
            if(dp[i][j-1]!=-1&&dp[dp[i][j-1]][j-1]!=-1)
                dp[i][j]=dp[dp[i][j-1]][j-1];
        }
    }
    for(int i=0;i<q;i++){
        int u,v;cin>>u>>v;
        int lev1=lev[u],lev2=lev[v];
        if(lev1>lev2){
            int diff=lev1-lev2;
            dbg(u,diff);
            u=binaryJump(u,lev1-lev2,par,n,mxJump,dp);
            dbg(u);
        }else if(lev1<lev2){
            v=binaryJump(v,lev2-lev1,par,n,mxJump,dp);
        }
        int lo=-1,hi=n;
        int mxLevel=0;//maxLevel of ansNode.
        int lca=1;
        while(hi-lo>1){
            int mid=lo+(hi-lo)/2;
            int u1=binaryJump(u,mid,par,n,mxJump,dp),v1=binaryJump(v,mid,par,n,mxJump,dp);
            if(u1==-1||v1==-1)hi=mid;
            else{
                if(u1==v1){
                    hi=mid;
                    if(lev[u1]>mxLevel){
                        mxLevel=lev[u1];
                        lca=u1;
                    }
                }else lo=mid;
            }
        }
        cout<<lca<<'\n';
    }


    return 0;
}