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
        int n;cin>>n;
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i].first;
            cin>>v[i].second;
        }
        int mxs=v[0].first;
        int fl=1;
        vector<int> e;
        for(int i=1;i<n;i++){
            if(v[i].first>=mxs){
                e.push_back(v[i].second);
            }
        }
        if(e.empty())cout<<v[0].first<<'\n';
        else{
            for(auto x:e){
                if(x>=v[0].second){
                    fl=0;
                    break;
                }
            }
            if(!fl)cout<<-1<<'\n';
            else{
                cout<<v[0].first<<'\n';
            }
        }
    }

    return 0;
}