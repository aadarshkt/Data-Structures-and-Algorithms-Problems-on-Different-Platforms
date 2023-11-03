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

    int x = 5;
    int y = ++x;
    int z = x++;
    cout<<y<<' '<<z<<'\n';
    //y is 6 
    //z is 6;

    return 0;
}