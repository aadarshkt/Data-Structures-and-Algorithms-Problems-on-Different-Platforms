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
    int m1,m2,m3,m4;
    cin>>m1>>m2>>m3>>m4;

    vector<pair<string,int>> arr(n);
    for(int i=0;i<n;i++){
        string name;
        int height;
        cin>>name>>height;
        arr[i]={name,height};
    }
    vector<vector<string>> ans(4);

    for(int i=0;i<n;i++){
        auto player=arr[i];
        if(player.second >= m1 and player.second < m2){
            ans[0].push_back(player.first);
        }else if(player.second >= m2 and player.second < m3){
            ans[1].push_back(player.first);
        }else if(player.second >= m3 and player.second < m4){
            ans[2].push_back(player.first);
        }else{
            ans[3].push_back(player.first);
        }
    }

    cout<<"S:"<<'\n';
    for(auto &i:ans[0]){
        cout<<i<<'\n';
    }

    cout<<"M:"<<'\n';
    for(auto &i:ans[1]){
        cout<<i<<'\n';
    }

    cout<<"L:"<<'\n';
    for(auto &i: ans[2]){
        cout<<i<<'\n';
    }

    cout<<"X:"<<'\n';
    for(auto &i:ans[3]){
        cout<<i<<'\n';
    }

    return 0;
}