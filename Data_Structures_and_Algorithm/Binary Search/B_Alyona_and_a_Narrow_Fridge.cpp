#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, h;
    cin >> n >> h;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    long long lo = 1, hi = n, mid = 0, tempH = 0, ans = 1;

    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;

        tempH = 0;

        int rev[mid];

        for(int i=0; i<mid; i++)
        {
            rev[i] = arr[i];
        }
        
        sort(rev, rev + mid);
        reverse(rev, rev + mid);

        for(int i=0; i<mid; i += 2)
        {
            tempH += rev[i];
        }

        if(tempH <= h)
        {
            lo = mid + 1;
            ans = max(ans, mid);
        }
        else if(tempH > h)
        {
            hi = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}