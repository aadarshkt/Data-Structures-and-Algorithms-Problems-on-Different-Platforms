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

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int l = 0;
        int x = 0, fl = 0;
        for(int i=0; i<n; i++){
            string s;cin>>s;
            l+=s.length();
            if(!fl && l == m){
                x = i+1;
                fl = 1;
            } else if(!fl && l > m) {
                x = i;
                fl = 1;
            } else if(!fl) {
                x = i + 1;
            }
        }
        cout << x << '\n';
    }

    return 0;
}