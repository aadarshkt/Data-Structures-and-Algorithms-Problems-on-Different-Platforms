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
        vector<vector<char>> v(8,vector<char>(8));
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cin>>v[i][j];
            }
        }
        string ans;
        for(int j=0;j<8;j++){
            for(int i=0;i<8;i++){
                if(v[i][j]!='.'){
                    ans.push_back(v[i][j]);
                }
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}