#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif



int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;cin>>n>>m;
    multiset<int> h;
    vector<int> t(m);
    for(int i=0;i<n;i++){
        int a;cin>>a;
        h.insert(a);
    }
    for(auto &x:t)cin>>x;
    for(int i=0;i<m;i++){
        auto it=h.lower_bound(t[i]);
        int val=*it;
        if(val==t[i]){
            cout<<val<<'\n';
            h.erase(it);
        }else{
            if(it==begin(h)){
                cout<<-1<<'\n';
            }else{
                it--;
                val=*it;
                cout<<val<<'\n';
                h.erase(it);
            }
        }
    }

    return 0;
}