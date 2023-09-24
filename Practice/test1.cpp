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
        int pos=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                pos=i;
                break;
            }
        }
        if(pos==-1){
            cout<<s<<'\n';
            continue;
        }
        for(int i=n-1;i>=pos;i--){
            if(i+2<n){
                s[i]='1',s[i+1]='0',s[i+2]='0';
            }
        }
        cout<<s<<'\n';
    }

    return 0;
}