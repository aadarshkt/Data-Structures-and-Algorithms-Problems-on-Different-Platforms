#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int arr[n];

    int mx = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }

    long long lo = mx, hi = 1e18, mid = 0;

    long long ans = INT_MAX;
    long long sum = 0, count = 1;

    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum > mid)
                count++, sum = arr[i];
        }

        if (count > k)
        {
            lo = mid + 1;
        }
        else
        {
            ans = mid;
            hi = mid - 1;
        }

        sum = 0;
        count = 1;
    }


    cout << ans << endl;

    return 0;
}