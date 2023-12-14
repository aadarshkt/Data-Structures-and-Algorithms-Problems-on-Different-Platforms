#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m)),diff(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        string s;cin>>s;
        for(int j=0;j<m;j++){
            v[i][j]=s[j]-'0';
        }
    }
    dbg(v);
    int q;cin>>q;
    for(int i=0;i<q;i++){
        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        x1--,x2--,y1--,y2--;
        diff[x1][y1]+=1;
        if(y2+1<m)diff[x1][y2+1]-=1;
        if(x2+1<n)diff[x2+1][y1]-=1;
        if(y2+1<m&&x2+1<n)diff[x2+1][y2+1]+=1;
        dbg(diff);
    }
    int sum=0;
    for(int j=0;j<m;j++){
        sum+=diff[0][j];
        diff[0][j]=sum;
    }
    sum=0;
    for(int i=0;i<n;i++){
        sum+=diff[i][0];
        diff[i][0]=sum;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(i-1>=0)diff[i][j]+=diff[i-1][j];
            if(j-1>=0)diff[i][j]+=diff[i][j-1];
            if(i-1>=0&&j-1>=0)diff[i][j]-=diff[i-1][j-1];
        }
    }
    dbg(diff);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(diff[i][j]%2==0){
                cout<<v[i][j];
            }else{
                cout<<!(v[i][j]);
            }
        }
        cout<<'\n';
    }


    return 0;
}