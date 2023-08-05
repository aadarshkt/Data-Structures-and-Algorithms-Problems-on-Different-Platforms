#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

bool detCyc(vector<int> &vis,vector<int> &parent,int s,vector<vector<int>> &adj){
    vis[s]=1;
    bool ans=0;
    for(auto i:adj[s]){
        if(vis[i]&&i!=parent[s]){
            ans=1;
            parent[i]=s;
            break;
        }
        if(!vis[i]){
            parent[i]=s;
            ans|=detCyc(vis,parent,i,adj);
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
        int n,m;cin>>n>>m;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<m;i++){
            int u,v;cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n+1,0),parent(n+1,-1);
        vector<pair<int,int>> ans;
        int fl=0;
        for(int i=1;i<=n;i++){
            if((int)adj[i].size()>=4){
                bool isCyc=detCyc(vis,parent,i,adj);
                if(isCyc){
                    int s=i;
                    int n1=parent[i];
                    while(parent[s]!=i){
                        ans.push_back({s,parent[s]});
                        s=parent[s];
                        if(s==-1)break;
                    }
                    ans.push_back({s,i});
                    int n2=s;
                    int cnt=0;
                    for(auto j:adj[i]){
                        if(j!=n1&&j!=n2){
                            ans.push_back({i,j});
                            cnt++;
                        }
                        if(cnt==2)break;
                    }  
                    fl=1;
                    cout<<"YES"<<'\n';
                    int k=ans.size();
                    cout<<k<<'\n';
                    for(auto ele:ans){
                        cout<<ele.first<<' '<<ele.second<<'\n';
                    }
                }else{
                    for(int i=1;i<=n;i++){
                        parent[i]=-1;
                        vis[i]=0;
                    }
                }
            }
        }
        if(!fl)cout<<"NO"<<'\n';

    }

    return 0;
}