#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int x[4]={1,-1,0,0},y[4]={0,0,1,-1};

int cnt=0;

void dfs(vector<vector<char>> &v,int i,int j,int n,int m,vector<vector<int>> &vis,int s,int k){
    vis[i][j]=1;
    for(int l=0;l<4;l++){
        int nextx=i+x[l],nexty=j+y[l];
        if(nextx<0||nextx>=n||nexty<0||nexty>=m||vis[nextx][nexty])continue;
        if(v[nextx][nexty]=='.'&&cnt<s-k){
            cnt++;
            dbg(cnt,s,k);
            dfs(v,nextx,nexty,n,m,vis,s,k);
        }
    }
}

int free(vector<vector<char>> &v,int i,int j,int n,int m,vector<vector<int>> &vis){
    vis[i][j]=1;
    int ans=1;
    for(int k=0;k<4;k++){
        int nextx=i+x[k],nexty=j+y[k];
        if(nextx<0||nextx>=n||nexty<0||nexty>=m||vis[nextx][nexty])continue;
        if(v[nextx][nexty]=='.'){
            ans+=free(v,nextx,nexty,n,m,vis);
        }
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,k;cin>>n>>m>>k;
    vector<vector<char>> v(n,vector<char>(m)),ans(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    vector<vector<int>> vis(n,vector<int>(m,0));
    int s=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j]&&v[i][j]=='.'){
                s+=free(v,i,j,n,m,vis);
            }
        }
    }
    dbg(s);
    vis.assign(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j]&&v[i][j]=='.'&&cnt<s-k){
                cnt=1;
                dfs(v,i,j,n,m,vis,s,k);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='.'&&!vis[i][j])ans[i][j]='X';
            else ans[i][j]=v[i][j];
            cout<<ans[i][j];
        }
        cout<<'\n';
    }
    dbg(cnt);
    cnt=0;


    return 0;
}