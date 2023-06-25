#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

void detectCyc(vector<vector<int>> &adj,int s,vector<int> &vis,vector<int> &rec,vector<int> &parent,int &loopStart){
    rec[s]=1;
    vis[s]=1;
    for(int i:adj[s]){
        if(vis[i]&&rec[i]&&loopStart==-1){
            parent[i]=s;
            loopStart=i;
        }
        if(!vis[i]){
            parent[i]=s;
            detectCyc(adj,i,vis,rec,parent,loopStart); 
        }
    }
    rec[s]=0;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int> rec(n+1,0),vis(n+1,0),parent(n+1,-1);
    int loopStart=-1;
    for(int i=1;i<=n;i++){
        if(loopStart!=-1)continue;
        if(!vis[i])detectCyc(adj,i,vis,rec,parent,loopStart);
    }
    // dbg(loopStart);
    // for(auto x:parent)cout<<x<<' ';
    // cout<<'\n';
    if(loopStart==-1){
        cout<<"IMPOSSIBLE"<<'\n';
        return 0;
    }
    int s=loopStart;
    vector<int> ans;
    ans.push_back(s);
    s=parent[s];
    while(s!=loopStart){
        ans.push_back(s);
        s=parent[s];
    }
    ans.push_back(s);
    reverse(begin(ans),end(ans));
    cout<<(int)ans.size()<<"\n";
    for(auto x:ans)cout<<x<<' ';

    return 0;
}