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
        int n,k;cin>>n>>k;
        vector<int> c(n);
        for(auto &x:c)cin>>x;
        map<int,vector<int>> mp1,mp2;
        for(int i=0;i<n;i++){
            if(!mp1.count(c[i])){
                mp1[c[i]].push_back(-1);
                mp1[c[i]].push_back(i);
            }
            else mp1[c[i]].push_back(i);
        }
        map<int,int> fl;
        for(int i=0;i<n;i++){
            if(!fl[c[i]])mp1[c[i]].push_back(n);
            fl[c[i]]=1;
        }
        for(auto x:mp1){
            int sz=x.second.size();
            dbg(t,sz);
            for(int i=1;i<sz;i++){
                dbg(t,x.second[i]);
                mp2[x.first].push_back(x.second[i]-x.second[i-1]-1);
            }
        }
        int mn=n+1;
        for(auto x:mp2){
            sort(begin(x.second),end(x.second));
            dbg(t,x.first,x.second);
            int sz=x.second.size();
            x.second[sz-1]/=2;
            sort(begin(x.second),end(x.second));
            mn=min(mn,x.second[sz-1]);
        }
        cout<<mn<<'\n';
    }

    return 0;
}