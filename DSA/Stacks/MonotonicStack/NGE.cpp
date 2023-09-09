#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

//for every element find pos of it's next strictly greater element

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    cout<<n<<'\n';
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    vector<int> st,ans(n,-1);
    for(int i=0;i<n;i++){
        if(st.empty())st.push_back(i);
        else{
            while(!st.empty()&&a[st.back()]<a[i]){
                ans[st.back()]=a[i];
                st.pop_back();
            }
            st.push_back(i);
        }
    }
    for(auto x:ans)cout<<x<<' ';

    return 0;
}