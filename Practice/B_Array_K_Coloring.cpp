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

    int n,k;cin>>n>>k;
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    if(n<k){
        cout<<"NO"<<"\n";
        return 0;
    }
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[a[i]]++;
    }
    int ans=1;
    vector<int> res(n);
    map<int,int> mp2;
    for(int i=0;i<n;i++){
        mp2[a[i]]=0;
    }
    map<int,vector<int>> mp3;
    int col=1;
    for(auto x:mp){
        if(x.second>k){
            ans=0;break;
        }else{
            for(int i=0;i<x.second;i++){
                mp3[x.first].push_back(col);
                col++;
                if(col>k)col=1;
            }
        }
    }
    if(ans){
        cout<<"YES"<<'\n';
        for(int i=0;i<n;i++){
            cout<<mp3[a[i]][mp2[a[i]]]<<' ';
            mp2[a[i]]++;
        }
    }
    else cout<<"NO"<<'\n';

    return 0;
}