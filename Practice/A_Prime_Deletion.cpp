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
        string s;cin>>s;
        int n=s.length();
        int fl=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                fl=1;break;
            }else if(s[i]=='3'){
                fl=2;break;
            }
        }
        if(fl==1)cout<<13<<'\n';
        else cout<<31<<'\n';
    }

    return 0;
}