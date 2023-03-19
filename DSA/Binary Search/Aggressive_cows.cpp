#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, c;
        cin >> n >> c;

        int arr[n];

        set<int> s;

        int stall = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            s.insert(arr[i]);
            stall = min(stall, arr[i]);
        }

        long long lo = 1, hi = 1e18, mid = 0, temp = stall, ans = 1;

        while (lo <= hi)
        {
            int count = 1;
            mid = lo + (hi - lo) / 2;
            stall = temp;

            auto it = s.lower_bound(stall);

            while (it != s.end())
            {
                it = s.lower_bound(stall + mid);
                if(it != s.end()) stall = *(it), count++;
            }

            if(count >= c)
            {
                ans = max(mid, ans);
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }

        cout << ans << endl;

        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    }

    return 0;
}