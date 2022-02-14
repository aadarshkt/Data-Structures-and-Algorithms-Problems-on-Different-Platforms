#include <bits/stdc++.h>
using namespace std;

//This problem can be done in three steps
// 1 -> find max to the left of a particular i.
// 2 -> Find max to the right of a particular i.
// 3 -> Find min of both for a particualr i and then subtract it to arr[i] to get
// the water holded by the particular i.

int maxWater(int arr[], int n)
{

    int max_ = INT_MIN, left[n], right[n];

    for (int i = 0; i < n; i++)
    {
        max_ = max(max_, arr[i]);
        left[i] = max_;
    }

    max_ = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        max_ = max(max_, arr[n - i - 1]);
        right[i] = max_;
    }

    //Now if we consider every i of left and right simultaneously we have max to the left of i and 
    // right of i

    int res = 0;

    for(int i=0; i<n; i++)
    {
        res += min(left[i], right[i]) - arr[i];
    }

    return res;
}

int main()
{

    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << maxWater(arr, n);

    return 0;
}