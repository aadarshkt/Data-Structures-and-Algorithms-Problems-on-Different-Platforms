#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int x[4]={1,-1,0,0},y[4]={0,0,1,-1};

int dfs(vector<vector<char>> &v,int n,int m, int i,int j,vector<vector<int>> &st,vector<vector<int>> &vis){
    if(v[i][j]=='L')return 1;
    else if(v[i][j]=='#')return 0;
    for(int k=0;k<4;k++){
        int nextx=i+x[k],nexty=j+y[k];
        if(nextx<0||nextx>=n||nexty<0||nexty>=m||vis[i][j])continue;
        if(st[nextx][nexty]==0||st[nextx][nexty]==1)return st[i][j];
        if(v[i][j]!='L')vis[i][j]=1;
        int res=dfs(v,n,m,nextx,nexty,st,vis);
        if(st[i][j]==-1)st[i][j]=res;
        else st[i][j]&=res;
    }
    return st[i][j];
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n,m;cin>>n>>m;
        vector<vector<char>> v(n,vector<char>(m)),ans(n,vector<char>(m));
        vector<vector<int>> st(n,vector<int>(m,-1)),vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>v[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]=='#')ans[i][j]='#';
                else if(v[i][j]=='L')ans[i][j]='L';
                else{
                    int res=dfs(v,n,m,i,j,st,vis);
                    if(res==1)ans[i][j]='+';
                    else ans[i][j]=v[i][j];
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<ans[i][j];
            }
            cout<<'\n';
        }
    }

    return 0;
}