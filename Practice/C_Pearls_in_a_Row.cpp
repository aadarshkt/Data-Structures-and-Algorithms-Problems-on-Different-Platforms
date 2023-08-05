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
    for(auto &x:v)cin>>x;
    set<int> st;
    int s,e;
    vector<pair<int,int>> ans;
    for(int i=0;i<n;i++){
        if((int)st.size()==0){
            s=i;
            st.insert(v[i]);
        }else{
            if(st.count(v[i])){
                e=i;
                ans.push_back({s,e});
                st.clear();
            }else st.insert(v[i]);
        }
    }
    int sz=ans.size();
    if(sz==0)cout<<-1<<'\n';
    else{
        ans[sz-1].second=n-1;
        cout<<ans.size()<<'\n';
        for(auto x:ans)cout<<x.first+1<<' '<<x.second+1<<'\n';

    }

    return 0;
}