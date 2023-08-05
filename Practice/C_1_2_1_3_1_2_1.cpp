#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

string print(int n){
    if(n==1)return "1";
    string res;
    string prev=print(n-1);
    res=prev+" "+to_string(n)+" "+prev;
    return res;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    string ans=print(n);
    cout<<ans<<'\n';

    return 0;
}