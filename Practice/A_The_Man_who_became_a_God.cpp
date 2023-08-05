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
        int n,k;cin>>n>>k;
        vector<int> a(n),diff;
        for(auto &x:a)cin>>x;
        for(int i=0;i<n-1;i++){
            diff.push_back(abs(a[i]-a[i+1]));
        }
        sort(rbegin(diff),rend(diff));
        int sum=0;
        for(int i=k-1;i<(int)diff.size();i++){
            sum+=diff[i];
        }
        cout<<sum<<'\n';
    }

    return 0;
}