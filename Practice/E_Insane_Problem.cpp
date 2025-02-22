#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;
        long long total = 0;

        // Handle n=0 case: y = x * 1 (k^0)
        long long new_low = max((long long)l1, (long long)l2);
        long long new_high = min((long long)r1, (long long)r2);
        if (new_low <= new_high) {
            total += new_high - new_low + 1;
        }

        // Handle n >=1 cases
        if (k > 1) { // since k >=2, this is always true
            long long k_power = k;
            while (k_power <= (long long)r2) {
                long long low_x = (l2 + k_power - 1) / k_power; // ceil(l2 / k_power)
                long long high_x = (long long)r2 / k_power;

                long long current_low = max((long long)l1, low_x);
                long long current_high = min((long long)r1, high_x);

                if (current_low <= current_high) {
                    total += current_high - current_low + 1;
                }

                // Check if next k_power would exceed r2
                if (k_power > (long long)r2 / k) {
                    break;
                } else {
                    k_power *= k;
                }
            }
        }

        cout << total << '\n';
    }
    return 0;
}