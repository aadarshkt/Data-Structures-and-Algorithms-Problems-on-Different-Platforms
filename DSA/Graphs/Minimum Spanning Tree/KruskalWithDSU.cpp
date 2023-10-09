#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42

#endif

long long ans=0;
void dfs(int node,vector<pair<int,int>> ad[],vector<bool> &vis){
    vis[node] = true;
    for(auto x: ad[node]){
        if(!vis[x.first]){
            ans+=x.second;
            dfs(x.first,ad,vis);
        }
    }
}
long getMaxReliability(int k,int n,vector<int> &u,vector<int> &v,vector<int> &w){
    vector<pair<int,int>> ad[n];
    vector<int> indeg(n);
    for(int i=0;i<n-1;i++){
        ad[u[i]].push_back({v[i],w[i]});
        ad[v[i]].push_back({u[i],w[i]});
        indeg[u[i]]++,indeg[v[i]]++;
    }
    vector<bool> vis(n,false);
    dfs(0,ad,vis);
    long maxcost = ans;
    bool done[n]{false};
    
    // for(int i=0;i<n;i++){
    //     if(ad[i].size()>k){
    //         vector<pair<int,int>> temp = ad[i];
    //         sort(temp.begin(),temp.end(),[](pair<int,int> a,pair<int,int> b){
    //             if(a.second== b.second){
    //                 return a.first<b.first;
    //             }
    //             return a.second<b.second;
    //         });
    //         int del = max(0, indeg[i]-k);
    //         for(auto x: temp){
    //             if(done[x.first]){
    //                 continue;
    //             }
    //             else{
    //                 done[x.first]
    //             }
    //         }

    //     }
    // }
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>> n;

    vector<int> u(n-1);
    vector<int> v(n-1);
    for(int i=0;i<n-1;i++){
        cin>> u[i];
    }
    for(int i=0;i<n-1;i++){
        cin>> v[i];
    }
    vector<int> w(n-1);
    for(int i=0;i<n-1;i++){
        cin>> w[i];
    }
    int k;
    cin>> k;
    cout<< getMaxReliability(k,n,u,v,w);

    return 0;
}