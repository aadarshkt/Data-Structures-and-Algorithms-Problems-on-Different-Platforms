#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

bool condition(const string &a,const string &b){
    return (a+b<b+a);
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<string> v(n);
    for(auto &x:v)cin>>x;
    sort(begin(v),end(v),condition);
    for(auto x:v)cout<<x;

    return 0;
}