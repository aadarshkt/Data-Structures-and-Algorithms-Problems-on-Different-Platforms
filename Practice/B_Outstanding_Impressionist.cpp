#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> ranges(n);
        vector<int> fixed_x;
        unordered_map<int, int> global_count;

        for (int i = 0; i < n; ++i) {
            int l, r;
            cin >> l >> r;
            ranges[i] = {l, r};
            if (l == r) {
                fixed_x.push_back(l);
                global_count[l]++;
            }
        }

        // Deduplicate fixed_x and sort
        sort(fixed_x.begin(), fixed_x.end());
        auto last = unique(fixed_x.begin(), fixed_x.end());
        fixed_x.erase(last, fixed_x.end());

        string ans;
        for (int i = 0; i < n; ++i) {
            int l = ranges[i].first, r = ranges[i].second;
            if (l == r) {
                int x = l;
                int cnt = global_count[x];
                if (cnt - 1 == 0) {
                    ans += '1';
                } else {
                    ans += '0';
                }
            } else {
                auto left = lower_bound(fixed_x.begin(), fixed_x.end(), l);
                auto right = upper_bound(fixed_x.begin(), fixed_x.end(), r);
                int count = right - left;
                int len = r - l + 1;
                if (len > count) {
                    ans += '1';
                } else {
                    ans += '0';
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}