#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;
        int sum = 0;
        vector<int> deltas;
        for (char c : n) {
            int digit = c - '0';
            sum += digit;
            if (digit == 2) {
                deltas.push_back(2);
            } else if (digit == 3) {
                deltas.push_back(6);
            }
        }
        if (sum % 9 == 0) {
            cout << "YES\n";
            continue;
        }
        int target = (9 - (sum % 9)) % 9;
        bitset<9> possible;
        possible.set(0); // Start with remainder 0
        for (int delta : deltas) {
            bitset<9> new_possible = possible;
            for (int r = 0; r < 9; ++r) {
                if (possible.test(r)) {
                    int new_r = (r + delta) % 9;
                    new_possible.set(new_r);
                }
            }
            possible = new_possible;
            if (possible.test(target)) {
                break;
            }
        }
        cout << (possible.test(target) ? "YES" : "NO") << '\n';
    }
    return 0;
}   