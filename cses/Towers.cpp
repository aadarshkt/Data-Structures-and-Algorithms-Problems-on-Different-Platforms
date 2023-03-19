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
    multiset<int> st;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        auto it=st.upper_bound(a);
        if(it==st.end()){
            st.insert(a);
        }else{
            st.erase(it);
            st.insert(a);
        }
    }
    cout<<(int)st.size()<<'\n';

    return 0;
}