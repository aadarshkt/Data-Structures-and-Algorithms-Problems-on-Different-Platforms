#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int calc(vector<int> &a,int n){
    int res=0;
    for(int i=1;i<=(2*n)-1;i+=2){
        res+=(-1)*(n-i)*a[(i-1)/2];
    }
    return res;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n,m;cin>>n>>m;
        vector<vector<int>> v(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>v[i][j];
            }
        }
        int ans=0;
        for(int j=0;j<m;j++){
            vector<int> a;
            for(int i=0;i<n;i++){
                a.push_back(v[i][j]);
            }
            sort(begin(a),end(a));
            ans+=calc(a,n);
            dbg(t,ans);
        }
        cout<<ans<<'\n';
    }

    return 0;
}