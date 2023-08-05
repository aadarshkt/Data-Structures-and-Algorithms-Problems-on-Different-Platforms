#include <bits/stdc++.h>
using namespace std;


#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;cin>>n;
        vector<int> v(n);
        for(auto &x:v)cin>>x;
        sort(begin(v),end(v));
        map<int,int> mp;
        int fl=1;
        for(int i=0;i<n;i++){
            if(v[i]==0)mp[0]++;
            else{
                if(mp[v[i]-1]==0){
                    fl=0;
                    break;
                }
                mp[v[i]-1]--;
                mp[v[i]]++;
            }
        }
        if(fl)cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }

    return 0;
}