#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};

bool inrange(int x,int y,int n){
    if(x>=n||x<0||y>=n||y<0)return false;
    return true;
}

int dfs(int x,int y,int n,int i,int k){
    if(i==k)return 1;
    int ans=0;
    for(int j=0;j<4;j++){
        int nxtx=x+dx[j],nxty=y+dy[j];
        if(!inrange(nxtx,nxty,n))continue;
        ans+=dfs(nxtx,nxty,n,i+1,k);
    }
    return ans;
}

int dfs1(int x,int y,int n,int i,int k){
    if(i==k)return 1;
    int ans=0;
    for(int j=0;j<4;j++){
        int nxtx=x+dx[j],nxty=y+dy[j];
        if(!inrange(nxtx,nxty,n)){
            ans+=1;
        }else {
            ans+=dfs(nxtx,nxty,n,i+1,k);
        }
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    int x,y;cin>>x>>y;
    int k;cin>>k;
    int p1=dfs(x,y,n,0,k);
    int p2=dfs1(x,y,n,0,k);
    dbg(p1,p2);
    double ans=(double)p1/p2;
    dbg(p1);
    cout<<ans<<'\n';



    return 0;
}