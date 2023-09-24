#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int scr(int x,int y){
    if(x==0){
        return 1;
    }else if(x==9)return 1;
    else if(y==0)return 1;
    else if(y==9)return 1;
    else if(x==1)return 2;
    else if(x==8)return 2;
    else if(y==1||y==8)return 2;
    else if(x==2||x==7)return 3;
    else if(y==2||y==7)return 3;
    else if(x==3||x==6||y==3||y==6)return 4;
    else if(x==4||x==5||y==4||y==5)return 5;
    return -1;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        vector<vector<char>> v(10,vector<char>(10));
        int cnt=0;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                cin>>v[i][j];
                if(v[i][j]=='X')cnt+=scr(i,j);
            }
        }
        cout<<cnt<<'\n';
    }


    return 0;
}