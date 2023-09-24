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
        int sum=0;
        for(auto &x:a){
            cin>>x;
            sum+=x;
        }
        if(sum%2==0)cout<<"YES"<<'\n';
        else cout<<"NO"<<"\n";
        
    }
 
    return 0;
}