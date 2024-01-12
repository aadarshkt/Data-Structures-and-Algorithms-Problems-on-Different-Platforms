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

    vector<int> arr = {1, 2};

    int indx = lower_bound(begin(arr),begin(arr)+1,20) - begin(arr);
    dbg(indx);
    cout<<indx<<'\n';

    return 0;
}