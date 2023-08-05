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
        vector<int> v(n),ans,ans1,ans2;
        for(auto &x:v)cin>>x;
        ans.push_back(v[0]);
        for(int i=1;i<n;i++){
            if(v[i]!=v[i-1]){
                ans.push_back(v[i]);
            }
        }
        ans1.push_back(v[0]);
        for(int i=1;i<(int)ans.size();i++){
            if(i+1>(int)ans.size()-1)ans1.push_back(ans[i]);
            else{
                if(!(ans[i]>ans[i-1]&&ans[i]<ans[i+1])){
                    ans1.push_back(ans[i]);
                }
            }

        }
        ans2.push_back(ans1[0]);
        for(int i=1;i<(int)ans1.size();i++){
            if(i+1>(int)ans1.size()-1)ans2.push_back(ans1[i]);
            else{
                if(!(ans1[i]<ans1[i-1]&&(ans1[i]>ans1[i+1]))){
                    ans2.push_back(ans[i]);
                }
            }
        }
        // cout<<t<<'\n';
        // for(auto &x:ans)cout<<x<<' ';
        // for(auto &x:ans1)cout<<x<<' ';
        // for(auto &x:ans2)cout<<x<<' ';
        cout<<ans2.size()<<'\n';
    }

    return 0;
}