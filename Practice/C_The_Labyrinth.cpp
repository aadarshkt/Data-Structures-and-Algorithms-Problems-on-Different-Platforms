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

int dfs(vector<vector<char>> &mat,int i,int j,vector<vector<int>> &vis,int n,int m,int uniq){
    vis[i][j]=uniq;
    int ans=0;
    for(int k=0;k<4;k++){
        int nextx=i+x[k],nexty=j+y[k];
        if(nextx<0||nextx>n-1||nexty<0||nexty>m-1||vis[nextx][nexty]||mat[nextx][nexty]=='*')continue;
        ans+=1+dfs(mat,nextx,nexty,vis,n,m,uniq);
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // int t;
    // cin >> t;
    // while(t--){
        int n,m;cin>>n>>m;
        vector<vector<char>> mat(n,vector<char>(m));
        vector<vector<string>> ans(n,vector<string>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>mat[i][j];
                // cout<<mat[i][j];
            }
        }
        map<int,int> mp;
        int uniq=1;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='.'&&!vis[i][j]){
                    int sz=1+dfs(mat,i,j,vis,n,m,uniq);
                    sz=sz%10;
                    mp[uniq]=sz;
                    uniq++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='*'){
                    set<int> st;
                    int res=0;
                    for(int k=0;k<4;k++){
                        int nextx=i+x[k],nexty=j+y[k];
                        if(nextx<0||nextx>n-1||nexty<0||nexty>m-1)continue;
                        if(!st.count(vis[nextx][nexty])){
                            st.insert(vis[nextx][nexty]);
                            res+=mp[vis[nextx][nexty]];
                        }
                    }
                    res++;
                    res=res%10;
                    ans[i][j]=to_string(res);
                }else ans[i][j]='.';
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<ans[i][j];
            }
            cout<<'\n';
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<vis[i][j];
        //     }
        //     cout<<'\n';
        // }
    // }

    return 0;
}