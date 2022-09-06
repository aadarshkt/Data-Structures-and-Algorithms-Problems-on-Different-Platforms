#include <bits/stdc++.h>
using namespace std;

int findOne(int arr[], int n)
{
    int pos = -1, lo = 0, hi = n - 1, mid = 0;

    while(lo <= hi)
    {
        mid = lo + (hi - lo) / 2;

        if(arr[mid] == 0)
        {
            lo = mid + 1;
        }
        else
        {
            pos = mid;
            hi = mid - 1;
        }
    }

    return pos;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {0, 0, 1, 1, 1, 1};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << findOne(arr, n);

    return 0;
}