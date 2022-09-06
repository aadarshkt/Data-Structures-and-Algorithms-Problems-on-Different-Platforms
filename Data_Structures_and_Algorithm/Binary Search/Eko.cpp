#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    long long mid = 0, w = 0, lo = 0, hi = 1e10, h = 0;

    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;

        w = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > mid)
                w += arr[i] - mid;
        }

        if (w < m)
        {
            hi = mid - 1;
        }
        else
        {
            h = mid;
            lo = mid + 1;
        }
    }

    cout << h << endl;

    return 0;
}