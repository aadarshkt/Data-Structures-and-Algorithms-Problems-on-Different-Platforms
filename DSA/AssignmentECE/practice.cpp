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

    int n;cin>>n;
    vector<vector<int>> cst(n,vector<int>(n,INT_MAX));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)cst[i][j]=0;
            else{
                if(cst[i][j]==INT_MAX){
                    cin>>cst[i][j];
                    cst[j][i]=cst[i][j];
                }
            }
        }
    }
    dbg(cst);
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cst[i][j]=min(cst[i][j],cst[i][k]+cst[k][j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cout<<cst[i][j]<<' ';
        cout<<'\n';
    }

    return 0;
}
