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
        vector<int> a(n);
        for(auto &x:a)cin>>x;
        vector<int> o,e;
        for(int i=0;i<n;i++){
            if(a[i]%2==0){
                e.push_back(a[i]);
            }else{
                o.push_back(a[i]);
            }
        }
        sort(rbegin(o),rend(o));
        sort(rbegin(e),rend(e));
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(a[i]%2==0){
                ans.push_back(e.back());
                e.pop_back();
            }else{
                ans.push_back(o.back());
                o.pop_back();
            }
        }
        sort(begin(a),end(a));
        int fl=1;
        for(int i=0;i<n;i++){
            if(a[i]!=ans[i]){
                fl=0;break;
            }
        }
        if(fl)cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";

    }

    return 0;
}