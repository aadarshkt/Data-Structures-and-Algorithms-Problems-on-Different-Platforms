#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int solve(vector<vector<int>> &pre,int n,int j,int prev){
    if(j==3)return 0;
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        if(i==prev)continue;
        ans=min(ans,pre[i][j]+solve(pre,n,j+1,i));
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;cin>>n>>m;
    vector<string> v;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        v.push_back(s);
    }
    //pre[i][0] -> for dig
    //pre[i][1] -> for letter
    //pre[i][2] -> for special character
    vector<vector<int>> pre(n,vector<int>(3,INT_MAX));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int dig=v[i][j]-'0';
            if(dig>=0&&dig<=9){
                pre[i][0]=min({pre[i][0],j,m-j});
            }
            int let=v[i][j]-'a';
            if(let>=0&&let<=25){
                pre[i][1]=min({pre[i][1],j,m-j});
            }
            if(v[i][j]=='#'||v[i][j]=='*'||v[i][j]=='&'){
                pre[i][2]=min({pre[i][2],j,m-j});
            }
        }
    }
    dbg(pre);
    cout<<solve(pre,n,0,-1)<<'\n';


    return 0;
}