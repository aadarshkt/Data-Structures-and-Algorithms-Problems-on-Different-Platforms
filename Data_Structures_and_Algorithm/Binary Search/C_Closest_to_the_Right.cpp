#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int n, int q)
{
    int lo = 0, hi = n - 1, mid = 0, ans = n;

    while(lo <= hi)
    {
        mid = lo + (hi - lo) / 2;

        if(arr[mid] < q) 
        {
            lo = mid + 1;
        }
        else if(arr[mid] == q)
        {
            ans = mid;
            hi = mid - 1;
        }
        else 
        {
            ans = mid;
            hi = mid - 1;
        }
    }

    return ans + 1;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int arr[n], q[k];

    for(int i=0; i<n; i++) cin >> arr[i];

    while(k--)
    {
        int q;
        cin >> q;

        cout << solve(arr, n, q) << endl;
    }

    


    return 0;
}