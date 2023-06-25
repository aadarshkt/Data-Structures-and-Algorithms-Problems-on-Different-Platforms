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
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    //spt -> spanning tree, vertices included into spanning tree.
    vector<int> spt(n+1,0);
    int mstCost=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        pair<int,int> fr=pq.top();
        int u=fr.second;
        pq.pop();
        mstCost+=fr.first;
        spt[u]=1;
        for(auto i:adj[u]){
            int v=i.first,w=i.second;
            if(!spt[v]){
                pq.push({w,v});
            }
        }
    }
    cout<<mstCost<<'\n';

    return 0;
}