#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long x, y;
        cin >> n >> x >> y;
        vector<long long> a(n);
        long long total = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            total += a[i];
        }
        long long low = total - y;
        long long high = total - x;
        sort(a.begin(), a.end());
        long long ans = 0;
        for (int j = 1; j < n; ++j) {
            long long lb = low - a[j];
            long long ub = high - a[j];
            auto left = lower_bound(a.begin(), a.begin() + j, lb);
            auto right = upper_bound(a.begin(), a.begin() + j, ub);
            ans += (right - left);
        }
        cout << ans << '\n';
    }
    return 0;
}