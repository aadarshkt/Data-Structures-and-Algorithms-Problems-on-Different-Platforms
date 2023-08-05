#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int DFS(vector<vector<int>> &adj,vector<int> &vis,int s,vector<pair<pair<int,int>,pair<int,int>>> &depth,vector<int> &parent){
    vis[s]=1;
    for(auto i:adj[s]){
        if(!vis[i]){
            int can=1+DFS(adj,vis,i,depth,parent);
            if(can>=depth[s].first.first){
                pair<int,int> fp=depth[s].first,sp=depth[s].second;
                sp.first=fp.first;
                sp.second=fp.second;
                fp.first=can;
                fp.second=i;
                depth[s].first=fp,depth[s].second=sp;
            }
            parent[i]=s;
        }
    }
    return depth[s].first.first;
}

int findDistanceToRoot(vector<int> &parent,int s){
    int ans=0;
    while(parent[s]!=-1){
        ans++;
        s=parent[s];
    }
    return ans;
}

void calculateUp(vector<int> &parent,int n,vector<pair<pair<int,int>,pair<int,int>>> &depth, int s,vector<int> &up){
    if(s==1)return;
    if(up[s]!=-1)return;
    if(up[parent[s]]==-1){
        if(depth[parent[s]].first.second!=s&&depth[parent[s]].first.first!=-1){
            up[s]=depth[parent[s]].first.first+1;
        }else{
            if(depth[parent[s]].second.first!=-1){
                up[s]=depth[parent[s]].second.first+1;
            }else{
                calculateUp(parent,n,depth,parent[s],up);
            }
        }
    }else{
        up[s]=up[parent[s]]+1;
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n,k,c;cin>>n>>k>>c;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n-1;i++){
            int u,v;cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n+1,0),parent(n+1,-1),disR(n+1,0);
        vector<pair<pair<int,int>,pair<int,int>>> depth(n+1);
        DFS(adj,vis,1,depth,parent);
        int ans=0;
        for(int i=1;i<=n;i++){
            disR[i]=findDistanceToRoot(parent,i);
        }
        //up[v] -> stores maximum depth you can reach from vertex v;
        vector<int> up(n+1,-1);
        for(int i=1;i<=n;i++){
            calculateUp(parent,n,depth,i,up);
        }
        for(int i=1;i<=n;i++){
            if(i==1){
                ans=max(ans,depth[1].first.first*k);
            }else{
                if(up[i]!=-1){
                    ans=max(ans,k*up[i]-c*disR[i]);
                }
            }
        }
        cout<<ans<<"\n";
        // for(auto &x:up)cout<<x<<' ';
        // cout<<'\n';
        // for(auto &x:disR)cout<<x<<' ';
        // cout<<'\n';
    }

    return 0;
}