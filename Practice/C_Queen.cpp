#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

void check(vector<vector<int>> &adj,int s,vector<int> &res,vector<int> &idx){
    int ans=1;
    for(auto i:adj[s]){
        if(res[i]!=1)ans=0;
    }
    if(ans==1&&res[s]==1)idx.push_back(s);
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<vector<int>> adj(n+1);
    vector<int> res(n+1);
    int root=1;
    for(int i=0;i<n;i++){
        int p,c;cin>>p>>c;
        res[i+1]=c;
        if(p==-1){root=i+1;continue;}
        adj[p].push_back(i+1);
    }
    dbg(adj);
    vector<int> idx;
    for(int i=1;i<=n;i++){
        check(adj,i,res,idx);
    }
    if(idx.empty()||((int)idx.size()==1&&idx[0]==root))cout<<-1<<'\n';
    else{
        sort(begin(idx),end(idx));
        dbg(root);
        dbg(idx,res);
        for(auto x:idx)
            if(x!=root){
                cout<<x<<' ';
            }
    }

    return 0;
}