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

    time_t curr_time = time(0) - 3600;
    string s = ctime(&curr_time);
    cout<<s<<'\n';

    return 0;
}