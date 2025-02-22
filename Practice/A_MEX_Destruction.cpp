#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/dbg.h>
#else
#define dbg(...) 42
#endif

#define int long 

int find_continuous(vector<int> &a, int n){
    int fl = 0,j = 0;
    int cnt = 0;
    dbg(a);
    while(j < n){
        while(j < n && a[j] != 0){
            j++;
            fl = 1;
        }
        dbg(fl, j);
        if(fl)cnt++;
        while(j < n && a[j] == 0){
            dbg(a[j]);
            j++;
        }
        fl = 0;
        dbg(fl, j);
    }
    dbg(cnt);
    return cnt;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        for(int &x:a)cin>>x;

        int cnt = find_continuous(a, n);
        dbg(cnt);
        if(cnt == 0) cout << 0 << '\n';
        else if(cnt == 1) cout << 1 << '\n';
        else cout << 2 << '\n';
    }

    return 0;
}