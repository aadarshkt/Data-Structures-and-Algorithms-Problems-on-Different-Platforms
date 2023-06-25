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
        vector<int> v(n);
        for(auto &x:v)cin>>x;
        set<int> st;
        for(auto x:v)st.insert(x);
        int fl=0,ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(st.count(v[i]+v[j])){
                    fl=1;
                    ans=v[i]+v[j];
                    break;
                }
            }
            if(fl)break;
        }
        cout<<ans<<'\n';
    }

    return 0;
}