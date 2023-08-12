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

    int n;cin>>n;
    string str="3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
    string ans="3.";
    for(int i=2;i<n+2;i++){
        ans.push_back(str[i]);
    }
    cout<<ans<<'\n';

    return 0;
}