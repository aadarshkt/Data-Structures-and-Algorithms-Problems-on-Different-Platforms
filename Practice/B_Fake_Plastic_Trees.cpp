#include <bits/stdc++.h>
using namespace std;

#define int long long

bool dump(int l1,int r1,int l2,int r2){
    return l2<l1&&r2<l1;
}

int dfs(vector<vector<int>> &adj,vector<int> &vis,int s,vector<pair<int,int>> &ran){
    vis[s]=1;
    int ans=0;
    for(auto i:adj[s]){
        if(!vis[i]){
            bool check=dump(ran[s].first,ran[s].second,ran[i].first,ran[i].second);
            if(check)ans+=1+dfs(adj,vis,i,ran);
            else ans+=dfs(adj,vis,i,ran);
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
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n-1;i++){
            int v;cin>>v;
            adj[i+2].push_back(v);  
            adj[v].push_back(i+2);  
        }
        vector<pair<int,int>> ran(n+1);
        for(int i=0;i<n;i++){
            int l,r;cin>>l>>r;
            ran[i+1]={l,r};
        }
        vector<int> vis(n+1,0);
        cout<<dfs(adj,vis,1,ran)<<'\n';
    }

    return 0;
}