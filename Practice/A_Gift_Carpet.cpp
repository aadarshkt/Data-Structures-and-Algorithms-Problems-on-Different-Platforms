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
        vector<set<char>> a(m);
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                a[j].insert(v[i][j]);
            }
        }
        int p=0;
        string s="vika";
        for(int i=0;i<m;i++){
            if(p==4)break;
            if(a[i].count(s[p])){
                p++;
            }
        }
        if(p<4)cout<<"NO"<<'\n';
        else cout<<"YES"<<"\n";
    }

    return 0;
}