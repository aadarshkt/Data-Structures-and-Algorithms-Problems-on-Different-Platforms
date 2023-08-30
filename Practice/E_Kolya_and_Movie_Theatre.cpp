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
        int n,m,d;cin>>n>>m>>d;
        vector<int> a(n);
        for(auto &x:a)cin>>x;
        multiset<int> st;
        int ans=0,sum=0;
        for(int i=0;i<n;i++){
            int curr=sum+a[i]-(i+1)*d;
            ans=max(ans,curr);
            if(a[i]>0){
                st.insert(a[i]);
                sum+=a[i];
                if((int)st.size()>m-1){
                    sum-=*st.begin();
                    st.erase(st.begin());
                }
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}