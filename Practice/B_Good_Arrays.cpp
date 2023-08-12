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
        if(n==1){
            cout<<"NO"<<'\n';
            continue;
        }
        int diff=0,cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]==1)cnt++;
            else diff+=a[i]-1;
        }
        if(diff>=cnt)cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }

    return 0;
}