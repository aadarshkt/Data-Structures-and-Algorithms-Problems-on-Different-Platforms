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
        reverse(begin(a),end(a));
        vector<int> ans;
        for(int i=1;i<=a[n-1];i++){
            int idx=lower_bound(begin(a),end(a),i)-begin(a);
            int cnt=n-idx;
            ans.push_back(cnt);
            if((int)ans.size()>n)break;
        }
        reverse(begin(a),end(a));
        if((int)ans.size()!=(int)a.size())cout<<"NO"<<"\n";
        else{
            int fl=1;
            for(int i=0;i<n;i++){
                if(ans[i]!=a[i]){
                    fl=0;break;
                }
            }
            if(fl)cout<<"YES"<<"\n";
            else cout<<"NO"<<'\n';
        }
    }

    return 0;
}