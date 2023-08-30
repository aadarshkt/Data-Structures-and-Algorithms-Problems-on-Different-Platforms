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
        vector<int> b(n);
        for(auto &x:b)cin>>x;
        vector<int> ans;
        ans.push_back(b[0]);
        for(int i=1;i<n;i++){
            if(ans.back()==1){
                ans.push_back(b[i]);
            }else if(b[i]==1){
                ans.push_back(1);
                ans.push_back(b[i]);
            }
            else{
                ans.push_back(min(b[i],b[i-1])-1);
                ans.push_back(b[i]);
            }
        }
        cout<<(int)ans.size()<<'\n';
        for(auto x:ans)cout<<x<<' ';
        cout<<"\n";
    }

    return 0;
}