#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long long

int *fun(int a){
    int *b = &a;
    return b;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string *s,y;
    string a = "hello";
    s = &a;
    y = a;

    cout<<s<<'\n';
    cout<<y<<'\n';

    int b = 5;
    int *c = &b;
    cout<<fun(b)<<'\n';
    cout<<c<<'\n';

    int e = 5, f = 10, g = 15;
    int *arr[3] = {&e, &f, &g};
    cout<<arr[1]<<'\n';

    return 0;
}