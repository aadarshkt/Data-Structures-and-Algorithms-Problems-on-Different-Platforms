#include <bits/stdc++.h>
using namespace std;

//Binary Search is an algorithm.

//The trick is if you divide a array into two parts only one and one part will be sorted.

//1-> check if first half is sorted.
//2-> check if the element is in sorted part.
//3-> if first point is not true then second half must be sorted.
//4-> check if element is present in sorted half. Otherwise give r = m - 1;
//5-> if second half is sorted and it is present in the second part then simply do l = m + 1; for next binary sorting.

//good solution could be done by own also.

int Search(int arr[], int l, int r, int x)
{
    int m;
    while (l <= r)
    {
        m = (l + r) / 2;

        if (arr[m] == x)
        {
            return m;
        }

        if (arr[m] > arr[l])
        {
            if(x < arr[m] && x >= arr[l])
            {
                r = m - 1;
            } else {
                l = m + 1;
            }
        } else {
            if(x <= arr[r] && x > arr[m])
            {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
    }

    return -1;
}

int main()
{

    int arr[] = {8, 9, 10, 1, 2, 3, 4, 5, 6, 7};

    int n = sizeof(arr) / sizeof(arr[0]);

    int x = 10;

    cout << "Index of the element is : " << Search(arr, 0, n - 1, x);

    return 0;
}