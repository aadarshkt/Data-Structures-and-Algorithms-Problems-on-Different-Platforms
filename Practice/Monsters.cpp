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

bool bfs(vector<vector<char>> &v,int n,int m,queue<pair<int,int>> q,vector<vector<int>> &vis,vector<vector<pair<int,int>>> &par,int &lastx,int &lasty){
    int ans=0;
    while(!q.empty()){
        pair<int,int> p=q.front();
        q.pop();
        if(v[p.first][p.second]=='A'){
            for(int k=0;k<4;k++){
                int nextx=p.first+x[k],nexty=p.second+y[k];
                if(!inrange(nextx,nexty,n,m)){
                    lastx=nextx,lasty=nexty;
                    ans=1;break;
                }else{
                    if(vis[nextx][nexty])continue;
                    if(v[nextx][nexty]!='.')continue;
                    par[nextx][nexty]={p.first,p.second};
                    vis[nextx][nexty]=1;
                    q.push({nextx,nexty});
                    v[nextx][nexty]='A';
                }
            }
        }else if(v[p.first][p.second]=='M'){
            for(int k=0;k<4;k++){
                int nextx=p.first+x[k],nexty=p.second+y[k];
                if(!inrange(nextx,nexty,n,m))continue;
                if(v[nextx][nexty]=='#')continue;
                if(vis[nextx][nexty])continue;
                vis[nextx][nexty]=1;
                v[nextx][nexty]='M';
                q.push({nextx,nexty});
            }
        }
        if(ans)break;
    }
    return ans;
}

char dir(int i,int j,int parx,int pary){
    if(parx-i==1)return 'U';
    else if(i-parx==1)return 'D';
    else if(pary-j==1)return 'L';
    return 'R';
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //pos[i][j] --> stores position of nearest monster (it's shortest distance from that cell.)

    int n,m;cin>>n>>m;
    vector<vector<char>> v(n,vector<char>(m));
    queue<pair<int,int>> q;
    vector<vector<pair<int,int>>> par(n,vector<pair<int,int>>(m,{-1,-1}));
    vector<vector<int>> vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
            if(v[i][j]=='A')vis[i][j]=1;
            else if(v[i][j]=='M')q.push({i,j});
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='A')q.push({i,j});
        }
    }
    int lastx=-1,lasty=-1;
    bool ans=bfs(v,n,m,q,vis,par,lastx,lasty);
    dbg(par);
    if(ans){
        vector<char> path;
        cout<<"YES"<<'\n';
        if(lastx>=n){
            lastx--;
        }
        else if(lastx<0){
            lastx++;
        }
        else if(lasty>=m){
            lasty--;
        }
        else if(lasty<0){
            lasty++;
        }
        dbg(lastx,lasty);
        while(lastx!=-1){
            pair<int,int> p=par[lastx][lasty];
            if(p.first==-1)break;
            char direc=dir(lastx,lasty,p.first,p.second);
            path.push_back(direc);
            lastx=p.first,lasty=p.second;
        }
        cout<<(int)path.size()<<'\n';
        reverse(begin(path),end(path));
        for(auto i:path)cout<<i;

    }else cout<<"NO"<<'\n';

    return 0;
}