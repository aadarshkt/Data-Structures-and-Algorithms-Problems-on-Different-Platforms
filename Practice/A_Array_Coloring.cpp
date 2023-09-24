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
        string s;cin>>s;
        int pos=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                pos=i;
                break;
            }
        }
        for(int i=pos+1;i<n;i++){
            if(s[i]=='1')s[i]='0';
        }
        cout<<s<<'\n';
    }

    return 0;
}