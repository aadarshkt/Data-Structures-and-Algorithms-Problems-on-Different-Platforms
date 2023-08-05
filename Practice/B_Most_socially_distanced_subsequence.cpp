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
        int i=0,j=1;
        vector<int> ans;
        ans.push_back(a[0]);
        ans.push_back(a[j]);
        j++;
        while(i<n&&j<n){
            int d1=abs(ans.back()-a[i]),d2=abs(a[j]-ans.back()),d3=abs(a[j]-a[i]);
            if(d1+d2==d3){
                ans.pop_back();
                ans.push_back(a[j]);
            }else{
                i=j-1;
                ans.push_back(a[j]);
            }
            j++;
        }
        int sz=ans.size();
        cout<<sz<<'\n';
        for(auto x:ans)cout<<x<<' ';
        cout<<'\n';
    }

    return 0;
}