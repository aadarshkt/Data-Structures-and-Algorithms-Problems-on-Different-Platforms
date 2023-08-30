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
        int x,y,n;cin>>x>>y>>n;
        vector<int> ans;
        int a=y;
        for(int i=0;i<n;i++){
            ans.push_back(a-i);
            a=a-i;
        }
        dbg(ans);
        if(ans.back()>=x){
            ans.pop_back();
            reverse(begin(ans),end(ans));
            cout<<x<<' ';
            for(int i=0;i<n-1;i++){
                cout<<ans[i]<<' ';
            }
            cout<<'\n';
        }else{
            cout<<-1<<'\n';
        }
    }

    return 0;
}