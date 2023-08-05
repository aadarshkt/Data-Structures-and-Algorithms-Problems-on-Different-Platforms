#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int x[4]={1,-1,0,0},y[4]={0,0,1,-1};

bool inrange(int i,int j,int n,int m){
    bool ans=0;
    if(i>=0&&i<n&&j>=0&&j<m)ans=1;
    return ans;
}

int dfs(vector<vector<char>> &v,vector<vector<int>> &vis,int i,int j,int n,int m,int prev,int id){
    vis[i][j]=id;
    int ans=0;
    for(int k=0;k<4;k++){
        if(k==prev)continue;
        int nx=i+x[k],ny=j+y[k];
        if(!inrange(nx,ny,n,m))continue;
        if(v[nx][ny]!='*'||vis[nx][ny])continue;
        // dbg(i,j,nx,ny,v[nx][ny]);
        ans+=1+dfs(v,vis,nx,ny,n,m,k,id);
    }
    return ans;
}

int dx[8]={1,1,1,0,0,-1,-1,-1},dy[8]={-1,0,1,-1,1,-1,0,1};

bool check(int i,int j,int n,int m,vector<vector<int>> &vis,vector<vector<char>> &v){
    int ans=1;
    for(int k=0;k<8;k++){
        int nx=i+dx[k],ny=j+dy[k];
        if(!inrange(nx,ny,n,m))continue;
        if(v[i][j]=='*'&&v[nx][ny]=='*'&&vis[i][j]!=vis[nx][ny]){
            ans=0;break;
        }
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
        vector<vector<char>> v(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>v[i][j];
            }
        }
        int ans=1;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int id=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int depth=0;
                if(v[i][j]=='*'&&!vis[i][j]){
                    depth=dfs(v,vis,i,j,n,m,-1,id);
                    id++;
                    if(depth!=2){
                        ans=0;break;
                    }
                }
                
            }
            if(!ans)break;
        }
        dbg(vis);
        if(!ans)cout<<"NO"<<'\n';
        else{
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(v[i][j]=='*'){
                        ans=check(i,j,n,m,vis,v);
                        if(!ans)break;
                    }
                }
                if(!ans)break;
            }
            if(ans)cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }
    }

    return 0;
}