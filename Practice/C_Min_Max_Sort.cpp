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
        vector<int> v(n);
        for(auto &x:v)cin>>x;
        int fl=0;
        for(int i=1;i<n;i++){
            if(v[i]<v[i-1])fl=1;
        }
        if(!fl){
            cout<<0<<'\n';
            continue;
        }
        int ans=0;
        if(n%2==0)ans=n/2;
        else ans=(n-1)/2;
        if(n%2==0){
            int first=n/2,second=first+1;
            if(v[0]==first&&v[n-1]==second)ans--;
        }else{
            int first=(n-1)/2,second=(n+3)/2;
            if(v[0]==first&&v[n-1]==second)ans--;
        }
        cout<<ans<<'\n';
    }

    return 0;
}