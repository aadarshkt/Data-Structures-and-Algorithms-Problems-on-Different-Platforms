#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

struct DSU{
    vector<int>e;
    DSU(int N){e=vector<int>(N,-1);}
    int get(int x) {return e[x]<0?x:e[x]=get(e[x]);}
    bool same_set(int a,int b){return get(a)==get(b);}
    int size(int x){return -e[get(x)];}
    bool unite(int x,int y){  // union by size
        x=get(x),y=get(y);
        if(x==y)return false;
        if(e[x]>e[y])swap(x,y);
        e[x]+=e[y];e[y]=x;
        return true;
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;cin>>n>>m;
    vector<pair<int,pair<int,int>>> edge;
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        edge.push_back({w,{u,v}});
    }
    sort(begin(edge),end(edge));
    DSU dsu=DSU(n+1);
    int mstCost=0;
    for(auto i:edge){
        int u=i.second.first,v=i.second.second,w=i.first;
        if(!dsu.same_set(u,v)){
            dsu.unite(u,v);
            mstCost+=w;
        }
    }
    int sz=dsu.size(1);
    if(sz!=n)cout<<"IMPOSSIBLE"<<'\n';
    else cout<<mstCost<<"\n";

    return 0;
}