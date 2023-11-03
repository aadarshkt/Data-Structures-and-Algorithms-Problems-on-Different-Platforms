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
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    vector<string> v;
    for(int i=0;i<n;i+=2){
        if(i+1<n){
            v.push_back(to_string(a[i])+to_string(a[i+1]));
        }else{
            v.push_back(to_string(a[i]));
        }
    }
    vector<int> a1;
    for(int i=0;i<(int)v.size();i+=2){
        if(i+1<(int)v.size()){
            a1.push_back(stoi(v[i])+stoi(v[i+1]));
        }else{
            a1.push_back(stoi(v[i]));
        }
    }
    vector<string> ans;
    for(int i=0;i<(int)a1.size();i+=2){
        if(i+1<(int)a1.size()){
            ans.push_back(to_string(a1[i])+to_string(a1[i+1]));
        }else{
            ans.push_back(to_string(a1[i]));
        }
    }
    for(auto s:ans)cout<<s<<' ';


    return 0;
}