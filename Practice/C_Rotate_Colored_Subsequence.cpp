#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

void fun(vector<int> &pos,string &s){
    int n=pos.size();
    string temp=s;
    char lst=s[pos[n-1]];
    for(int i=1;i<n;i++){
        s[pos[i]]=temp[pos[i-1]];
    }
    s[pos[0]]=lst;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;cin>>n>>m;
    string s;cin>>s;
    vector<vector<int>> col(m+1);
    for(int i=0;i<n;i++){
        int c;cin>>c;
        col[c].push_back(i);
    }
    dbg(col);
    for(int i=1;i<=m;i++){
        fun(col[i],s);
    }
    cout<<s<<'\n';

    return 0;
}