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
        vector<int> arr(n);
        for(auto &x:arr)cin>>x;
        sort(rbegin(arr),rend(arr));
        int ans=0;
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                ans++;
                cout<<ans<<" ";
            }else{
                ans--;
                cout<<ans<<' ';
            }
        }
        cout<<"\n";
        int both=0,one=0;
        set<int> st;
        for(int i=0;i<n;i++){
            if(st.count(abs(arr[i]))){
                both++;
                one--;
            }else {
                st.insert(abs(arr[i]));
                one++;
            }
        }
        for(int i=0;i<both;i++){
            cout<<1<<' '<<0<<' ';
        }
        int p=1;
        for(int i=0;i<one;i++){
            cout<<p<<' ';
            p++;
        }
        dbg(both,one);
        cout<<'\n';
    }

    return 0;
}