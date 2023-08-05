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
        vector<vector<char>> v(3,vector<char>(3));
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cin>>v[i][j];
            }
        }
        if(v[0][0]==v[0][1]&&v[0][2]==v[0][1]&&v[0][1]!='.'){cout<< v[0][0] << endl ;continue;}
        if(v[1][0]==v[1][1]&&v[1][2]==v[1][1]&&v[1][1]!='.'){cout<<v[1][0]<<'\n';continue;}
        if(v[2][0]==v[2][1]&&v[2][2]==v[2][1]&&v[2][1]!='.'){cout<<v[2][1]<<'\n';continue;}
        if(v[0][0]==v[1][0]&&v[2][0]==v[1][0]&&v[1][0]!='.'){cout<<v[1][0]<<'\n';continue;}
        if(v[0][1]==v[1][1]&&v[2][1]==v[1][1]&&v[1][1]!='.'){cout<<v[1][1]<<'\n';continue;}
        if(v[0][2]==v[1][2]&&v[2][2]==v[1][2]&&v[1][2]!='.'){cout<<v[1][2]<<'\n';continue;}
        if(v[0][0]==v[1][1]&&v[2][2]==v[1][1]&&v[1][1]!='.'){cout<<v[1][1]<<'\n';continue;}
        if(v[2][0]==v[1][1]&&v[0][2]==v[1][1]&&v[1][1]!='.'){cout<<v[1][1]<<'\n';continue;}
        cout<<"DRAW"<<'\n';
    }

    return 0;
}