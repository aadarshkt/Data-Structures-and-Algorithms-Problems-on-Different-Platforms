#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long
vector<int>e;
struct DSU{
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

    int n;cin>>n;
    vector<vector<int>> mat(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    DSU dsu=DSU(n);
    int ans=1;
    for(int i=0;i<n;i++){
        int res=1;
        for(int j=0;j<n;j++){
            if(j>i){
                if(mat[i][j]<=0)continue;
                if(!dsu.same_set(i,j)){
                    res=0;
                }else dsu.unite(i,j);
            }
            ans&=res;
        }
    }
    if(!ans){
        cout<<"NO"<<'\n';
        return 0;
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(e[dsu.get(i)]==-1)cnt++;
        dbg(dsu.get(i));
    }
    dbg(cnt);
    if(cnt>1)cout<<"NO"<<'\n';
    else cout<<"YES"<<'\n';


    return 0;
}