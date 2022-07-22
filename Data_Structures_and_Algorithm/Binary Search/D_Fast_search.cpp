#include <bits/stdc++.h>
using namespace std;

pair<int, int> findIdx(int arr[], int n, int l, int r)
{
    int lo = 0, hi = n - 1, mid = 0, minPos = -1, maxPos = -1;

    while(lo <= hi)
    {
        mid = lo + (hi - lo) / 2;

        if(arr[mid] < l)
        {
            lo = mid + 1;
        }
        else
        {
           hi = mid - 1;
           minPos = mid; 
        }
    }

    lo = 0, hi = n - 1, mid = 0;

    while(lo <= hi)
    {
        mid = lo + (hi - lo) / 2;

        if(arr[mid] > r)
        {
            hi = mid - 1;
        }
        else
        {
           lo = mid + 1;
           maxPos = mid; 
        }
    }

    pair<int, int> p;
    p.first = minPos, p.second = maxPos;

    return p;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int arr[n];

    for(int i=0; i<n; i++) cin >> arr[i];

    sort(arr, arr + n);

    int k;
    cin >> k;

    while(k--)
    {
        int l, r;
        cin >> l >> r;

        pair<int, int> p;
        p = findIdx(arr, n, l, r);
        cout << p.second - p.first + 1 << " ";
    }

    return 0;
}