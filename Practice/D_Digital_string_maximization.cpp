#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            a[i] = s[i] - '0';

        vector<vector<int>> events(n + 1);
        for (int i = 0; i < n; ++i) {
            int l = max(0, i - a[i]);
            int r = i - 1;
            if (l > r) continue;
            events[l].push_back(i);
        }

        priority_queue<pair<int, int>> pq;
        vector<int> res(n);

        for (int j = 0; j < n; ++j) {
            // Add all events for j
            for (int i : events[j]) {
                int val = a[i] - (i - j);
                pq.push({val, i});
            }
            // Remove elements where j > r
            while (!pq.empty() && pq.top().second - 1 < j)
                pq.pop();
            if (!pq.empty()) {
                res[j] = pq.top().first;
                pq.pop();
            } else {
                res[j] = a[j];
            }
        }

        for (int x : res)
            cout << x;
        cout << '\n';
    }
    return 0;
}