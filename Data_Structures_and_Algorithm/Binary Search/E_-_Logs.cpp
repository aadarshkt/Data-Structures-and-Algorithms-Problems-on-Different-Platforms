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

    int maxNum = 1;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        maxNum = max(maxNum, arr[i]);
    }

    long long lo = 1, hi = 1e18, mid = 0, cuts = 0, ans = 0;

    while(lo <= hi)
    {
        mid = lo + (hi - lo) / 2;

        cuts = 0;

        for(int i=0; i<n; i++)
        {
            cuts += (arr[i] - 1) / mid;
        }

        if(cuts <= k)
        {
            ans = mid;
            hi = mid - 1;
        }
        else if(cuts > k)
        {
            lo = mid + 1;
        }
    }


    if(k == 0) cout << maxNum << endl;
    else cout << ans << endl;

    return 0;
}