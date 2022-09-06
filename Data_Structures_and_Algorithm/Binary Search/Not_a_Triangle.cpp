#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            return 0;

        long long arr[n];

        for (long long i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr + n);

        long long count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                long long sum = arr[i] + arr[j];
                int lo = j + 1, hi = n - 1, mid = 0, idx = 0;

                while (lo <= hi)
                {
                    mid = lo + (hi - lo) / 2;

                    if (arr[mid] > sum)
                    {
                        idx = mid;
                        hi = mid - 1;
                    }
                    else if (arr[mid] <= sum)
                    {
                        lo = mid + 1;
                    }
                }

                if (idx > 1)
                    count += n - idx;
            }
        }

        cout << count << endl;
    }

    return 0;
}