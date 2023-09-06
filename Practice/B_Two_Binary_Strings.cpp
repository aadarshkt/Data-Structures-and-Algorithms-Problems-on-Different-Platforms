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
        string a,b;cin>>a>>b;
        int n=a.length();
        int fl=0;
        for(int i=0;i<n-1;i++){
            if(a[i]=='0'&&b[i]=='0'&&a[i+1]=='1'&&b[i+1]=='1'){
                fl=1;
                break;
            }
        }
        if(fl)cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }

    return 0;
}