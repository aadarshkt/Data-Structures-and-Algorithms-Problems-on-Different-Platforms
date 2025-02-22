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
        int n, k;cin>>n>>k;
        vector<int> a(n, -1);
        int cnt = 1;
        for(int i=k-1;i<n;i+=k){
            a[i] = cnt;
            cnt++;
        }
        for(int i=0; i<n; i++){
            if(a[i] == -1){
                a[i] = cnt;
                cnt++;
            }
        }
        for(int x: a)cout << x << ' ';
        cout<<'\n';
    }

    return 0;
}