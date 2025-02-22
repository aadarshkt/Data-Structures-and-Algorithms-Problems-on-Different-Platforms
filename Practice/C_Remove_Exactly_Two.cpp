#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long
vector<int> id;
vector<vector<int>> adj;
vector<pair<int,int>> ind;
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;cin>>n;
        adj.clear();
        id.clear();
        ind.clear();
        id.resize(n);
        ind.resize(n);
        adj.resize(n);
       for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            id[v]++,id[u]++;
        }
        for(int i=0;i<n;i++){
            ind.push_back(id[i], i);
        }

        sort(ind.rbegin(), ind.rend());
        int mx = ind[0].first;
        map<int, int>mp;
        for(int i=0; i<n; i++){
            mp[ind[i].second] = ind[i].first;
        }
        int ans=0;
        for(int i=0; i<n; i++){
            if(mx==ind[i].first){
                int x = ind[i].first;
                for(auto y: adj[x]){
                    if(mp[y]==mx){
                        ans = max(ans, mp[y]+mx-2);
                    }
                    else{
                        ans = max(ans, mp[y]+mx-1);
                    }
                }
            }
        }
        cout << ans << '\n';


    }

    return 0;
}