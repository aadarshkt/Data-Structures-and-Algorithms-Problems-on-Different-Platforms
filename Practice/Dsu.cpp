#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

// struct DSU{
//     vector<int>e;
//     DSU(int N){e=vector<int>(N,-1);}
//     int get(int x) {return e[x]<0?x:e[x]=get(e[x]);}
//     bool same_set(int a,int b){return get(a)==get(b);}
//     int size(int x){return -e[get(x)];}
//     bool unite(int x,int y){  // union by size
//         x=get(x),y=get(y);
//         if(x==y)return false;
//         if(e[x]>e[y])swap(x,y);
//         e[x]+=e[y];e[y]=x;
//         return true;
//     }
// };

struct DSU {
    vector<int> e,mn,mx;
    DSU(int N){e=vector<int>(N,-1),mn=vector<int>(N,INT_MAX),mx=vector<int>(N,INT_MIN);}
    int get(int x){return e[x]<0?x:x=get(e[x]);}
    int getMin(int x){return mn[get(x)]==INT_MAX?x:mn[get(x)];}
    int getMax(int x){return mx[get(x)]==INT_MIN?x:mx[get(x)];}
    bool same_set(int a,int b){return get(a)==get(b);}
    int size(int x){return -e[get(x)];}
    bool unite(int x,int y){
        x=get(x),y=get(y);
        if(x==y)return false;
        if(e[x]>e[y])swap(x,y);
        e[x]+=e[y];e[y]=x;
        mn[x]=min({mn[x],x,y,mn[y]}),mx[x]=max({mx[x],x,y,mx[y]});
        return true;
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;cin>>n>>m;
    DSU dsu=DSU(n+1);
    for(int i=0;i<m;i++){
        string que;cin>>que;
        if(que=="union"){
            int u,v;cin>>u>>v;
            dsu.unite(u,v);
        }else{
            int v;cin>>v;
            cout<<dsu.getMin(v)<<' '<<dsu.getMax(v)<<' '<<dsu.size(v)<<'\n';
        }
            dbg(i, dsu.e);
            dbg(i, dsu.mx);
            dbg(i, dsu.mn);
    }

    return 0;
}