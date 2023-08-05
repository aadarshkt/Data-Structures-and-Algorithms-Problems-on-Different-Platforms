#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif
 
#define int long long
 
int cycLen(vector<vector<int>> &adj,vector<int> &vis,int n,int s){
    vis[s]=1;
    int ans=0;
    for(auto i:adj[s]){
        int deg=adj[i].size();
        if(deg==4)continue;
        if(!vis[i]){
            ans=max(ans,1+cycLen(adj,vis,n,i));
        }
    }
    return ans;
}
 
int mainCyc(vector<vector<int>> &adj,vector<int> &vis,int n,int s,vector<int> &parent, int &end){
    vis[s]=1;
    int ans=0;
    for(auto i:adj[s]){
        int deg=adj[i].size();
        if(deg!=4)continue;
        if(vis[i]&&i!=parent[s]){
            if(!end)end=i;
        }
        if(!vis[i]){
            // dbg(s,i);
            parent[i]=s;
            ans+=1+mainCyc(adj,vis,n,i,parent, end);
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
        // string s;cin>>s;
        int n,m;cin>>n>>m;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<m;i++){
            int u,v;cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt=0,cnt2=0,ocnt=0;
        for(int i=1;i<=n;i++){
            int deg=adj[i].size();
            if(deg==4)cnt++;
            else if(deg==2)cnt2++;
            else {
                ocnt++;
            }
        }
        if(cnt<3||ocnt){
            cout<<"NO"<<'\n';
        }else{
            dbg(t,cnt);
            vector<int> vis(n+1,0);
            int fl=1;
            for(int i=1;i<=n;i++){
                int deg=adj[i].size();
                if(deg==4){
                    int len=cycLen(adj,vis,n,i);
                    dbg(t,len+1);
                    if(len+1!=cnt){
                        fl=0;
                        break;
                    }
                }
            }
            if(n!=cnt*cnt)fl=0;
            if(m!=cnt*(cnt+1))fl=0;
            if(cnt2!=(cnt-1)*cnt)fl=0;
            for(int i=1;i<=n;i++){
                int deg=adj[i].size();
                if(deg!=2&&deg!=4){
                    fl=0;
                }
            }
            int start=0,cnt3=0;
            for(int i=1;i<=n;i++){
                int deg=adj[i].size();
                if(deg==4){
                    vis[i]=0;
                    start=i;
                    cnt3++;
                }
            }
            dbg(fl);
            vector<int> parent(n+1,-1);
            int end=0;
            int l=mainCyc(adj,vis,n,start,parent,end);
            if(l+1!=cnt3||end!=start)fl=0;
            // for(auto &x:parent)cout<<x<<" ";
            // cout<<'\n';
            dbg(l,cnt3,start,end);
            if(fl)cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }
    }
 
    return 0;
}