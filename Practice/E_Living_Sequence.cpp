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
        int k;cin>>k;
        vector<int> dig;
        while(k>0){
            dig.push_back(k%9);
            k/=9;
        }
        string ans="";
        for(auto x:dig){
            if(x>3)ans+=to_string(x+1);
            else ans+=to_string(x);
        }
        reverse(begin(ans),end(ans));
        cout<<ans<<"\n";
    }

    return 0;
}