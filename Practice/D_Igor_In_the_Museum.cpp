#include <bits/stdc++.h>
using namespace std;
 
 
#define int long long
 
const int x[4]={1,-1,0,0};
const int y[4]={0,0,1,-1};
 
int flood(vector<vector<char>> &mat,int i,int j,int n,int m,vector<vector<int>> &vis,int uniq){
    vis[i][j]=uniq;
    if(mat[i][j]=='*'){
        vis[i][j]=0;
        return 1;
    }
    int ans=0;
    for(int k=0;k<4;k++){
        if(i+x[k]>=0&&i+x[k]<n&&j+y[k]>=0&&j+y[k]<m&&!vis[i+x[k]][j+y[k]]){
            ans+=flood(mat,i+x[k],j+y[k],n,m,vis,uniq);
        }   
    }
    return ans;
}
 
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n,m,k;cin>>n>>m>>k;
    vector<vector<char>> v(n,vector<char>(m));
    vector<vector<int>> vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    map<int,int> p;
    int ans=0;
    for(int i=0;i<k;i++){
        int sx,sy;cin>>sx>>sy;
        sx--,sy--;
        if(vis[sx][sy])cout<<p[vis[sx][sy]]<<'\n';
        else {
            ans=flood(v,sx,sy,n,m,vis,i+1);
            p[i+1]=ans;
            cout<<ans<<'\n';
        }
    }
 
    return 0;
}