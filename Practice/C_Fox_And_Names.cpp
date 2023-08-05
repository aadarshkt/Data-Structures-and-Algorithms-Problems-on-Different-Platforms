#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long


bool detectCycleInDAG(vector<vector<int>> &adj,int s,vector<int> &vis,vector<int> &rec){
    vis[s]=1;
    rec[s]=1;
    int ans=0;
    for(auto i:adj[s]){
        if(rec[i]==1){dbg(s,i);ans=1;break;}
        if(!vis[i]){
            ans|=detectCycleInDAG(adj,i,vis,rec);
        }
    }
    rec[s]=0;
    return ans;
}

void topo(vector<vector<int>> &adj,int s,vector<int> &vis,vector<int> &sorted){
    vis[s]=1;
    for(auto i:adj[s]){
        if(!vis[i]){
            topo(adj,i,vis,sorted);
        }
    }
    sorted.push_back(s);
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<string> v;
    int mx=0;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        mx=max(mx,(int)s.length());
        v.push_back(s);
    }
    vector<vector<int>> adj(26);
    int k=0,l=1;
    while(k<mx&&l<n){
        k=0;
        int prev=v[l-1][k]-'a',curr=v[l][k]-'a';
        if(prev!=curr){
            adj[prev].push_back(curr);
            l++;
        }else{
            while(prev==curr){
                k++;
                if((int)v[l].length()<k+1){
                    cout<<"Impossible"<<'\n';
                    return 0;
                }else{
                    if((int)v[l-1].length()>=k+1){
                        prev=v[l-1][k]-'a',curr=v[l][k]-'a';
                        char ch1=prev+'a',ch2=curr+'a';
                        dbg(ch1,ch2);
                    }else break;
                }    
            }
            if(prev!=curr)adj[prev].push_back(curr);
            l++;
        }
    }
    vector<int> vis(26,0),rec(26,0);
    for(int i=0;i<26;i++){
        int isCyc=detectCycleInDAG(adj,i,vis,rec);
        if(isCyc){
            dbg(i);
            cout<<"Impossible"<<'\n';
            return 0;
        }
    }
    vector<int> sorted;
    vis.assign(26,0);
    for(int i=0;i<26;i++){
        if(!vis[i])topo(adj,i,vis,sorted);
    }
    dbg(sorted);
    reverse(begin(sorted),end(sorted));
    vector<int> fl(26,0);
    for(auto i:sorted){
        fl[i]=1;
    }
    for(int i=0;i<26;i++){
        if(!fl[i])sorted.push_back(i);
    }
    for(auto i:sorted){
        cout<<char(i+'a');
    }

    return 0;
}