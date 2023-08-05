#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

bool DFS(vector<set<int>> &adj,int s,vector<int> &vis,vector<int> &parent){
    vis[s]=1;
    int ans=0;
    for(auto i:adj[s]){
        if(vis[i]&&i!=parent[s]){
            ans=1;
        }
        if(!vis[i]){
            parent[i]=s;
            ans|=DFS(adj,i,vis,parent);
        }
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;cin>>n;
        vector<int> v(n);
        for(auto &x:v)cin>>x;
        vector<set<int>> adj(n+1);
        vector<int> vis(n+1,0),parent(n+1,-1);
        for(int i=0;i<n;i++){
            adj[i+1].insert(v[i]);
            adj[v[i]].insert(i+1);
        }
        int cnt1=0,cnt2=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                bool isCyc=DFS(adj,i,vis,parent);
                dbg(t,isCyc,i);
                if(isCyc)cnt1++;
                else cnt2++;
            }
        }
        dbg(t,cnt1,cnt2);
        int mx=cnt1+cnt2,mn=cnt1;
        if(cnt2>0)mn++;
        cout<<mn<<' '<<mx<<'\n';
    }

    return 0;
}