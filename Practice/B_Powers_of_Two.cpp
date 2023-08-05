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
    vector<int> v(n);
    map<int,int> mp;
    for(auto &x:v){
        cin>>x;
        mp[x]++;
    }
    vector<int> po;
    for(int i=1;i<=33;i++){
        po.push_back(pow(2,i));
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(auto x:po){
            if(x>v[i]){
                if(mp.count(x-v[i])){
                    if(x-v[i]==v[i])ans+=mp[x-v[i]]-1;
                    else ans+=mp[x-v[i]];
                }
            }
        }
    }
    cout<<ans/2<<'\n';

    return 0;
}