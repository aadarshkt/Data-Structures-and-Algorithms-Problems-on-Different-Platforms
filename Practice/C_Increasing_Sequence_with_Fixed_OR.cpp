#include <bits/stdc++.h>
using namespace std;

vector<long long> solve(long long n) {
    if ((n & (n - 1)) == 0) { // Check if n is a power of two
        return {n};
    }
    vector<long long> res;
    long long highest = 1LL << (63 - __builtin_clzll(n));
    long long current = highest;
    res.push_back(current);
    while (current < n) {
        long long next_bit = (n ^ current) & -(n ^ current); // Find the least significant missing bit
        current += next_bit;
        res.push_back(current);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> ans = solve(n);
        cout << ans.size() << '\n';
        for (long long x : ans) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}