#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...)
#endif

#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n,x;cin>>n>>x;
        vector<vector<int>> v(3,vector<int>(n,0));
        for(int i=0;i<3;i++){
            for(int j=0;j<n;j++){
                cin>>v[i][j];
            }
        }
        dbg(v);
        int k=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<n;j++){
                int d=v[i][j]|x;
                if(d==x){
                    k|=v[i][j];
                }else{
                    break;
                }
            }
        }
        if(k==x)cout<<"Yes"<<'\n';
        else cout<<"No"<<'\n';
    }

    return 0;
}