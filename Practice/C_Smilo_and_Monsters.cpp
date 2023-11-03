#include <bits/stdc++.h>
#define all(x) begin(x),end(x)

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
        int n; cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        sort(all(a));
        int  r = n-1;
        int ans = 0;
        int x = 0;
        for(int i=0;i<n;i++){
            if(i > r) break;
            if(i == r){
                if(a[i] == 1){
                    ans += 1;
                }else{
                    ans += (a[i] - x) / 2 + 1;
                    int d = a[i] - x;
                    if(d % 2) ans += 1;
                }
            }else{
                int k = min(a[i],a[r] - x);
                a[i] -= k;
                ans += k;
                x += k;
                if(x == a[r]){
                    ans += 1;
                    x = 0;
                    r--;
                }
                if(a[i] > 0){
                    if(i == r){
                        if(a[i] == 1){
                            ans += 1;
                        }else{
                            ans += (a[i] - x) / 2 + 1;
                            int d = a[i] - x;
                            if(d % 2) ans++;
                        }
                        
                    }else{
                        x += a[i];
                        ans += a[i];
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}