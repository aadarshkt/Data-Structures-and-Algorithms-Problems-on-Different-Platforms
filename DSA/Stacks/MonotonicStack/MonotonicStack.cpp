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
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    stack<int> st;
    for(int i=0;i<n;i++){
        if(st.empty())st.push(a[i]);
        else{
            if(st.top()>a[i])st.push(a[i]);
            else{
                while(!st.empty()&&st.top()<a[i]){
                    //those element poping are acutally elements whose nge is a[i];
                    cout<<st.top()<<"-->"<<a[i]<<'\n';
                    st.pop();
                }
                st.push(a[i]);
            }
        }
    }
    //those elements remaining have no nge.Refer example of gfg.
    while(!st.empty()){
        cout<<st.top()<<"-->"<<-1<<'\n';
        st.pop();
    }

    return 0;
}