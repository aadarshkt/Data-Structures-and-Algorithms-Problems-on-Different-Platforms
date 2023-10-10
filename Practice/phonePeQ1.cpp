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

    int t;cin>>t;
    for(int tt=0;tt<t;tt++){
        int n,m;cin>>n>>m;
        vector<vector<int>> a(3,vector<int>(n));
        for(int i=0;i<3;i++){
            for(int j=0;j<n;j++)cin>>a[i][j];
        }
        int ans=0;
        for(int k=0;k<3;k++){
            for(int i=0;i<n;i++){
                int fl=1;
                for(int j=0;j<30;j++){
                    if((!(m&(1<<j))) && (a[k][i]&(1<<j))){
                        fl=0;break;
                    }
                }
                if(fl)ans|=a[k][i];
                else break;
            }
        }
        if(ans==m)cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    return 0;
}