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

    for(int i=0; i<n; i++) cin >> arr[i];

    while(k--)
    {
        int q;
        cin >> q;

        int lo = 0, hi = n - 1, mid = 0, ans = -1;

        while(lo <= hi)
        {
            mid = lo + (hi - lo) / 2;

            if(arr[mid] > q)
            {
                hi = mid - 1;
            }
            else
            {
                ans = mid;
                lo = mid + 1;
            }
        }

        cout << ans + 1 << endl;
    }

    return 0;
}