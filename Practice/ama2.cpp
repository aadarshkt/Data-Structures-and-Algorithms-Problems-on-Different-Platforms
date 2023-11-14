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
    if(n%2!=0){
        cout<<0<<'\n';
        return 0;
    }
    n=n/2;
    if(n%2==0)cout<<(n/2)-1<<'\n';
    else cout<<(n/2)<<'\n';

    return 0;
}