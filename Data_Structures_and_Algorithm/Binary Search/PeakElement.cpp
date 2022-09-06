#include <bits/stdc++.h>
using namespace std;

//Good Problem.


//The trick to understand this problem is if the mid element is not peak(Greater than or equal to both of its neighbours)
//means anyneighbour must be greater than the mid element itself.
//SO we proceed to the side of greater element by doing r = m - 1 or l = m + 1;
//the main thing is if we go the side of greater element there must be peak element in that side
// Check yourself.

int findPeak(int arr[], int n, int l, int r)
{
    int m;
    if(arr[0] >= arr[1]) return 0;
    if(arr[n-1] >= arr[n-2]) return n-1;


    while (l <= r)
    {
        m = (l + r) / 2;



        if(arr[m-1] <= arr[m] && arr[m+1] <= arr[m])
        {
            return m;
        }
        
        if(m > 0 && arr[m-1] >= arr[m])
        {
            r = m - 1;
        } else {
            l = m + 1;
        }


    }

    return -1;
}

int main()
{

    int arr[] = {18 ,20 ,24, 15, 21, 5};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Index of a peak point is " << findPeak(arr, n, 0, n - 1);

    return 0;
}