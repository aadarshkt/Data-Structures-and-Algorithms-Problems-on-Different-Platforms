#include <bits/stdc++.h>
using namespace std;

string bSearch(int arr[], int n, int q)
{
    int lo = 0, hi = n - 1, mid = 0;
    
    while(lo <= hi)
    {
        mid = lo + (hi - lo) / 2;

        if(arr[mid] == q)
        {
            return "YES";
        }
        else if(arr[mid] < q)
        {
            lo = mid + 1;
        }
        else if(arr[mid] > q)
        {
            hi = mid - 1;
        }
    }

    return "NO";
}
 
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
        cout << bSearch(arr, n, q) << endl;
    }

    return 0;
}