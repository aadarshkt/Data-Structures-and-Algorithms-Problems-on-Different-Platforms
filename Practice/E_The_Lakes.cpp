#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

const int x[4]={1,-1,0,0};
const int y[4]={0,0,1,-1};

int DFS(vector<vector<int>> &mat,int i,int j,vector<vector<int>> &vis,int n,int m){
    vis[i][j]=1;
    int ans=mat[i][j];
    for(int k=0;k<4;k++){
        int nextx=i+x[k],nexty=j+y[k];
        if(nextx<0||nextx>n-1||nexty<0||nexty>m-1||vis[nextx][nexty]||mat[nextx][nexty]==0)continue;
        ans+=DFS(mat,nextx,nexty,vis,n,m);
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
        vector<vector<int>> mat(n,vector<int>(m)),vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>mat[i][j];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&mat[i][j]!=0){
                    ans=max(ans,DFS(mat,i,j,vis,n,m));
                }
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}