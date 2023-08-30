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

    string s;cin>>s;
    int n=s.length();
    int j=1;
    cout<<j<<". ";
    for(int i=0;i<n;i++){
        cout<<s[i];
        if(s[i]=='o'){
            cout<<'\n';
            j++;
            cout<<j<<". ";
        }
    }

    return 0;
}