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
        int n,m;cin>>n>>m;
        vector<vector<int>> gr(n+1);
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        map<int,int> mp;
        int x=0,y=0;
        for(int i=1;i<=n;i++){
            int nei=gr[i].size();
            if(nei==1)continue;
            dbg(t,nei);
            mp[nei]++;
        }
        if(mp.size()==1){
            auto it=mp.begin();
            x=it->first;
            y=x;
        }else{
            for(auto ele:mp){
                if(ele.second==1)x=ele.first;
                else y=ele.first;
            }
        }
        cout<<x<<' '<<y-1<<'\n';
    }
 
    return 0;
}